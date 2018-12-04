#include "AllarmEngine.hpp"

AllarmEngine::AllarmEngine(HardwareInterface *hardwareInterface,
                           ImageCapturer *imageCapturer) {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;
}

AllarmEngine::~AllarmEngine() {}

void AllarmEngine::poll() {}
