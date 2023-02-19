#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    control = new Controller();
    ui->pushButton_procesar->setEnabled(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_abrir_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), ".",tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));

   if(control->setInputImage(fileName.toStdString().data()))
   {
          ui->pushButton_procesar->setEnabled(true);
          cv::Mat mostrar;
          cv::cvtColor(control->getInputImage(),mostrar,CV_BGR2RGB);
          QImage img= QImage((const unsigned char*)(mostrar.data),mostrar.cols,mostrar.rows,QImage::Format_RGB888);
          img=img.scaled(ui->label->size(),Qt::KeepAspectRatio);
          ui->label->setPixmap(QPixmap::fromImage(img));
   }
   return;
}

void MainWindow::on_pushButton_procesar_clicked()
{
if(ui->lineEdit->text()!="")
    {
    cv::Mat erosionada,dilatada,cerrada;

    // Proceso la imagen de entrada y muestro el resultado de la binarización
    control->process();

    cv::imshow("Binarizada",control->getLastResult());
    QString nivel=ui->lineEdit->text();
    cv::Mat m_ruido(nivel.toInt(),nivel.toInt(),CV_8U,cv::Scalar(1));

    cv::erode(control->getLastResult() , erosionada , m_ruido , cv::Point(-1,-1) , 1);
    cv::imshow("erosionado",erosionada);
    cv::dilate(erosionada, dilatada , cv::Mat() , cv::Point(-1,-1) , 1);
    cv::imshow("Erosion+dilatacion",dilatada);
    //Cierre de la imagen dilatada
    cv::morphologyEx(dilatada,cerrada,cv::MORPH_CLOSE,cv::Mat());
    cv::imshow("cerrada",cerrada);
    //-----------------------------------------------------------------------------------
    // Segmenta la imagen


    cv::Mat bg,fg;
    cv::Mat mascara(ui->horizontalSlider_2->value(),ui->horizontalSlider_2->value(),CV_8U,cv::Scalar(1));
    // Identifica píxeles que pertenecen al area de interes (foreground)
    cv::dilate(cerrada,fg,mascara,cv::Point(-1,-1),1);
    // Identifica píxeles que no pertenecen al area de interes (background)
    cv::dilate(cerrada , bg , mascara , cv::Point(-1,-1) , 3);
    cv::threshold(bg,bg,1,128,cv::THRESH_BINARY_INV);


    //Crea los markers de la imagen, sumando la binarizada(áreas de interes)y el fondo
    cv::Mat markers(cerrada.size(),CV_8U,cv::Scalar(0));
    markers = fg+bg;
    cv::imshow("marcadores",markers);
    //Seteo markers
    control->setMarkers(markers);
    //Creo la imagen segmentada
    cv::Mat image_seg;
    image_seg = control->process_segment(control->getInputImage());
    //Crea una imagen que se pueda mostrar
    image_seg.convertTo(image_seg, CV_8U);
    cv::threshold(image_seg, image_seg, 150, 255, CV_THRESH_BINARY);
    cv::imshow("Imagen segmentada",image_seg);







    // Polígonos aproximados para contorno

    std::vector<std::vector<cv::Point> > poly_vector(control->getContours().size());
    control->setlong(nivel.toInt());
    poly_vector = control->process_contornos(image_seg);

    cv::Mat image_poligonos = cv::Mat::ones( image_seg.size(), CV_8UC3 );
    cv::RNG rng(12345);
    for( uint i = 0; i < control->getContours().size(); i++ )
        {
        cv::Scalar color = cv::Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        std::vector<cv::Point>::iterator itp = poly_vector[i].begin();

        while (itp!=(poly_vector[i].end()-1))
            {
            cv::line(image_poligonos,*itp,*(itp+1),color,3);
            ++itp;
            }
        // last point linked to first point
        cv::line(image_poligonos, *(poly_vector[i].begin()), *(poly_vector[i].end()-1),color,3);
         }

    //Uno la imagen original con los poligonos y la muestro
    cv::Mat image_union_poli;
    cv::add(control->getInputImage(),image_poligonos,image_union_poli);
    //cv::imshow( "Imagen mas poligonos",image_union_poli );

    QImage img= QImage((const unsigned char*)(image_union_poli.data),image_union_poli.cols,image_union_poli.rows,QImage::Format_RGB888);
    img=img.scaled(ui->label_4->size(),Qt::KeepAspectRatio);
    ui->label_4->setPixmap(QPixmap::fromImage(img));

    }
}

