#include "controller.h"


/*......Funciones Correspondientes a la detección de color y binarización........*/

bool Controller::setInputImage(std::string filename) {

    image= cv::imread(filename);

    if (!image.data)
       return false;
    else
       return true;

}

const cv::Mat Controller::getInputImage() const {
return image;
}

void Controller::process() {
    result = cdetect->process(image, result);
}

const cv::Mat Controller::getLastResult() const {
    return result;
}


void Controller::setDistance(int distance) {
    cdetect->setDistance(distance);
}



/*......Funciones Correspondientes a la segmentación........*/

void Controller::setMarkers(const cv::Mat& markerImage) {

    seg->setMarkers(markerImage);
}

cv::Mat Controller::process_segment(const cv::Mat &image) {

    return  seg->process_segment(image);

}



/*......Funciones Correspondientes a la generación de polígonos........*/

const std::vector<std::vector<cv::Point> > Controller::process_contornos(cv::Mat& image) {

    return poli->process_contornos(image);
}

const std::vector<std::vector<cv::Point> > Controller::getContours(void){


    return poli->getContours();

}

void Controller::setlong(int longitud)
{
    poli->setlong(longitud);
}
