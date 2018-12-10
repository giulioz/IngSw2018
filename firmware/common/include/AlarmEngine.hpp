#pragma once

#include "HardwareInterface.hpp"
#include "Webcam/ImageCapturer.hpp"
#include "DB/DB.hpp"
#include "DB/Entity/Root.hpp"
#include "DB/Entity/Intrusion.hpp"

class AlarmEngine {
 private:
  HardwareInterface *hardwareInterface;
  ImageCapturer *imageCapturer;
  DB *db;
  Root *root;
  int lastDepth;

  void triggerAlarm();

 public:
  bool active;
  bool autoActivated;

  AlarmEngine(HardwareInterface *hardwareInterface,
              ImageCapturer *imageCapturer, DB *db, Root *root);
  ~AlarmEngine();

  void setAlarmState(bool active);
  void setAutoState(bool active);

  void poll();
};
