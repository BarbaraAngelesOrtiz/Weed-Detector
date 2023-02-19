#ifndef SEGMENTER_H
#define SEGMENTER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Segmenter
{
    private:
        cv::Mat markers;

    public:

        Segmenter();

        void setMarkers(const cv::Mat&);

        cv::Mat process_segment(const cv::Mat&);


};

#endif // SEGMENTER_H
