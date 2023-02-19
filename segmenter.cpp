#include "segmenter.h"

Segmenter::Segmenter()
{
}

void Segmenter::setMarkers(const cv::Mat& markerImage) {
    // Convert to image of ints
    markerImage.convertTo(markers,CV_32S);
}


cv::Mat Segmenter::process_segment(const cv::Mat &image) {

    // Apply watershed
    cv::watershed(image,markers);
    return markers;
}
