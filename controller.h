#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <colordetector.h>
#include <segmenter.h>
#include <poligonos.h>

class Controller
{
    private:

       // objetos de clases de algoritmos
       ColorDetector *cdetect;
       Segmenter *seg;
       Poligonos *poli;

       cv::Mat image;   // La imagen a ser procesada
       cv::Mat result;  // La imagen resultante de la binarización

    public:

       Controller() {
           //Instanciación de los objetos
           cdetect = new ColorDetector();
           seg = new Segmenter();
           poli = new Poligonos();
       }

       // Deletes processor objects created by the controller.
       ~Controller() {
           delete cdetect;
           delete seg;
           delete poli;
        }


       /*......Funciones Correspondientes a la detección de color y binarización........*/
       bool setInputImage(std::string);
       const cv::Mat getInputImage() const;
       void process();
       const cv::Mat getLastResult() const;
       void setDistance(int);

       /*......Funciones Correspondientes a la segmentación ......*/
       void setMarkers(const cv::Mat& );
       cv::Mat process_segment(const cv::Mat &);


       /*......Funciones Correspondientes a la generación de poligonos ......*/
       void setlong (int);
       const std::vector<std::vector<cv::Point> > process_contornos(cv::Mat&);
       const std::vector<std::vector<cv::Point> > getContours(void);


};

#endif // CONTROLLER_H
