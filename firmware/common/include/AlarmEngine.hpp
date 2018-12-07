#pragma once

#include "HardwareInterface.hpp"
#include "Webcam/ImageCapturer.hpp"

class AlarmEngine {
 private:
  HardwareInterface *hardwareInterface;
  ImageCapturer *imageCapturer;

 public:
  bool active;
  bool autoActivated;

  AlarmEngine(HardwareInterface *hardwareInterface,
              ImageCapturer *imageCapturer);
  ~AlarmEngine();

  void setAlarmState(bool active);
  void setAutoState(bool active);

  void poll();
};
