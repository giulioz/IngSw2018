#pragma once

#include <unistd.h>
#include <opencv2/core/ocl.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

using namespace cv;
using namespace std;

class MotionDetector {
 private:
  void (*callback)(void);
  Mat firstFrame;
  VideoCapture camera;

 public:
  MotionDetector(void (*)(void));

  void poll();
};
