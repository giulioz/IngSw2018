#include "AlarmEngine.hpp"

#include <ctime>
#include <fstream>
#include <iostream>

#define THRESHOLD 30

AlarmEngine::AlarmEngine(HardwareInterface *hardwareInterface,
                         ImageCapturer *imageCapturer, DB *db, Root *root) {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;
  this->db = db;
  this->root = root;

  active = false;
  autoActivated = false;
  lastDepth = hardwareInterface->getDistance();
}

AlarmEngine::~AlarmEngine() {}

void AlarmEngine::setAlarmState(bool active) { this->active = active; }

void AlarmEngine::setAutoState(bool active) {}

void AlarmEngine::poll() {
  auto depth = hardwareInterface->getDistance();

  if (abs(depth - lastDepth) > THRESHOLD) {
    if (active) {
      triggerAlarm();
    }

    lastDepth = depth;
  }
}

void AlarmEngine::triggerAlarm() {
  auto time = std::time(0);

  std::string fileName = "intrusion_";
  fileName += std::to_string(time);
  fileName += ".jpg";

  auto imageBytes = imageCapturer->captureJpeg();

  std::ofstream imgFile(fileName, std::ios::out | std::ios::binary);
  imgFile.write(reinterpret_cast<char *>(imageBytes.data()), imageBytes.size());
  imgFile.close();

  Intrusion intrusion(time, time, false);
  root->getIntrusions().push_back(intrusion);
  db->store(*root);

  hardwareInterface->playAlarm();
}
