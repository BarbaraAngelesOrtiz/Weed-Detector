#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QMainWindow>
#include <controller.h>
#include <QFileDialog>
#include <QColorDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_abrir_clicked();
    void on_pushButton_procesar_clicked();

private:

    Ui::MainWindow *ui;
    Controller *control;

};

#endif // MAINWINDOW_H
