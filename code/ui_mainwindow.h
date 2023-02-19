/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_abrir;
    QLabel *label;
    QPushButton *pushButton_procesar;
    QLabel *label_4;
    QSlider *horizontalSlider_2;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1085, 452);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icono/Simplefly-Simple-Green-Leaf.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1);
        MainWindow->setIconSize(QSize(72, 72));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_abrir = new QPushButton(centralwidget);
        pushButton_abrir->setObjectName(QString::fromUtf8("pushButton_abrir"));
        pushButton_abrir->setGeometry(QRect(40, 70, 89, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 40, 361, 341));
        pushButton_procesar = new QPushButton(centralwidget);
        pushButton_procesar->setObjectName(QString::fromUtf8("pushButton_procesar"));
        pushButton_procesar->setGeometry(QRect(40, 100, 89, 23));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(590, 40, 361, 341));
        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(30, 250, 111, 19));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 180, 101, 20));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(60, 280, 42, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(100);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 150, 101, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 230, 61, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1085, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), pushButton_procesar, SLOT(click()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider_2, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), pushButton_procesar, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Detector de maleza", 0, QApplication::UnicodeUTF8));
        pushButton_abrir->setText(QApplication::translate("MainWindow", "Abrir imagen", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton_procesar->setText(QApplication::translate("MainWindow", "Procesar", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Tama\303\261o minimo (pix)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Selectividad", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
