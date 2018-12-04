#pragma once

#include "HardwareInterface.hpp"
#include "Webcam/ImageCapturer.hpp"

class AllarmEngine {
 private:
  HardwareInterface *hardwareInterface;
  ImageCapturer *imageCapturer;

 public:
  AllarmEngine(HardwareInterface *hardwareInterface,
         ImageCapturer *imageCapturer);
  ~AllarmEngine();

  void poll();
};
