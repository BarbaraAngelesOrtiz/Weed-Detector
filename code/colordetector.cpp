#include "colordetector.h"

cv::Mat ColorDetector::process(const cv::Mat &image, cv::Mat &result) {

      result.create(image.rows,image.cols,CV_8U);
      cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
      cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
      cv::Mat_<uchar>::iterator itout = result.begin<uchar>();
        uchar b,g,r;

        for ( ; it!= itend; ++it, ++itout) {
          b=(*it)[0];
          g=(*it)[1];
          r=(*it)[2];
          *itout=(2*g-b-r);
         }
      cv::threshold(result,result,umb,255,CV_THRESH_BINARY_INV);
    return result;

}

void ColorDetector::setDistance(int distance) {
    umb=distance;
}
