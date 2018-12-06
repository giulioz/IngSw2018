#pragma once

#include <opencv2/core/ocl.hpp>
#include <opencv2/opencv.hpp>

class ImageCapturer {
 private:
  cv::VideoCapture camera;

 public:
  ImageCapturer();
  ImageCapturer(const char* videoId);
  ~ImageCapturer();

  std::vector<uchar> captureJpeg();
};
