#pragma once

#include <opencv2/core/ocl.hpp>
#include <opencv2/opencv.hpp>

class MotionDetector {
 private:
  void (*callback)(void);
  cv::Mat firstFrame;
  cv::VideoCapture camera;
  bool first;

 public:
  MotionDetector(void (*)(void));

  void poll();
};
