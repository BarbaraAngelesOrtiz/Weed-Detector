#ifndef WATERSHEDSEGMENTER_H
#define WATERSHEDSEGMENTER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class WatershedSegmenter
{
    private:
        cv::Mat markers;

    public:

        WatershedSegmenter();


        void setMarkers(const cv::Mat&);

        cv::Mat process_segment(const cv::Mat&);


};

#endif // WATERSHEDSEGMENTER_H
