#include "AlarmEngine.hpp"

AlarmEngine::AlarmEngine(HardwareInterface *hardwareInterface,
                           ImageCapturer *imageCapturer) {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;
}

AlarmEngine::~AlarmEngine() {}

void AlarmEngine::poll() {}
