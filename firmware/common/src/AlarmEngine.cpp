#include "AlarmEngine.hpp"

AlarmEngine::AlarmEngine(HardwareInterface *hardwareInterface,
                         ImageCapturer *imageCapturer) {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;

  active = false;
  autoActivated = false;
}

AlarmEngine::~AlarmEngine() {}

void AlarmEngine::setAlarmState(bool active) {}

void AlarmEngine::setAutoState(bool active) {}

void AlarmEngine::poll() {}
