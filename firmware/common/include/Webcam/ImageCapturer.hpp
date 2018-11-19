#pragma once

#include <unistd.h>
#include <opencv2/core/ocl.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

using namespace cv;
using namespace std;

class ImageCapturer {
 private:
  VideoCapture camera;

 public:
  ImageCapturer();

  Mat capture();
};
