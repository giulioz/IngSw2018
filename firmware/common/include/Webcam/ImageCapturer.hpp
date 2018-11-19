#pragma once

#include <opencv2/core/ocl.hpp>
#include <opencv2/opencv.hpp>

class ImageCapturer {
 private:
  cv::VideoCapture camera;

 public:
  ImageCapturer();

  std::vector<uchar> capture();
};
