#include "poligonos.h"

std::vector<std::vector<cv::Point> > Poligonos::process_contornos(cv::Mat& image){

    //std::vector<std::vector<cv::Point> > contours;
    cv::findContours(image,
    contours, // a vector of contours
    CV_RETR_EXTERNAL, // retrieve the external contours (CV_RETR_EXTERNAL) o retrieve all contours (CV_RETR_LIST)
    CV_CHAIN_APPROX_NONE); // all pixels of each contours
/*

    // Eliminate too short contours
    std::vector<std::vector<cv::Point> >::iterator itc= contours.begin();
    while (itc!=contours.end()) {
      if (itc->size() < longmin )
         itc = contours.erase(itc);
      else
         ++itc;
    }
*/

    std::vector<cv::Point> poly;
    std::vector<cv::Point> hull;
    std::vector<std::vector<cv::Point> > poly_vector(contours.size());


    for( unsigned int i = 0; i < contours.size(); i++ ){

        cv::convexHull(cv::Mat(contours[i]),hull);

        //Aplico la aproximacion con polígonos a las elipses
        cv::approxPolyDP(cv::Mat(hull),poly,
                       5,     // accuracy of the approximation
                       true); // yes it is a closed shape

        //Guardo el nuevo polígono en el vector de polígonos
         poly_vector[i] = poly;

    }


   return poly_vector;

}


const std::vector<std::vector<cv::Point> > Poligonos::getContours(){
    return contours;
}


void Poligonos::setlong(int longitud)
{
    longmin=longitud;
}
