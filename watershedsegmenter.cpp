#include "watershedsegmenter.h"

WatershedSegmenter::WatershedSegmenter()
{
}

void WatershedSegmenter::setMarkers(const cv::Mat& markerImage) {
    // Convert to image of ints
    markerImage.convertTo(markers,CV_32S);
}


cv::Mat WatershedSegmenter::process_segment(const cv::Mat &image) {

    // Apply watershed
    cv::watershed(image,markers);
    return markers;
}
