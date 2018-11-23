#include "Comm.hpp"

Comm::Comm(HardwareInterface *hardwareInterface, ImageCapturer *imageCapturer,
           const char *infoString)
    : server(),
      webApi(&server, hardwareInterface, imageCapturer, infoString),
      pairing(&server, infoString) {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }
