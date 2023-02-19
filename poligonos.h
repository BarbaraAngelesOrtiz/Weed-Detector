#ifndef POLIGONOS_H
#define POLIGONOS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Poligonos
{

    private:
        std::vector<std::vector<cv::Point> > contours;
        int longmin;
    public:
        Poligonos(){
            longmin=100;
        };
        std::vector<std::vector<cv::Point> > process_contornos(cv::Mat&);
        const std::vector<std::vector<cv::Point> > getContours(void);
        void setlong(int);


};

#endif // POLIGONOS_H
