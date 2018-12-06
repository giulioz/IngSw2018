#pragma once

#include "HardwareInterface.hpp"
#include "Webcam/ImageCapturer.hpp"

class AlarmEngine {
 private:
  HardwareInterface *hardwareInterface;
  ImageCapturer *imageCapturer;

 public:
  AlarmEngine(HardwareInterface *hardwareInterface,
         ImageCapturer *imageCapturer);
  ~AlarmEngine();

  void poll();
};
