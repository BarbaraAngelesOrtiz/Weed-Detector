#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class ColorDetector {

    public:        
        cv::Mat process(const cv::Mat& ,cv::Mat&);
        void setDistance(int);

        ColorDetector() {
            umb=175;
        }

    private:

        double umb;     //Umbral de binarizacion, 175 por default

};

#endif // COLORDETECTOR_H
