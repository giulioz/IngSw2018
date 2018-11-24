#include "Comm.hpp"

Comm::Comm(HardwareInterface *hardwareInterface, ImageCapturer *imageCapturer,
           UI *ui, const char *infoString)
    : server(),
      webApi(&server, hardwareInterface, imageCapturer, infoString),
      pairing(&server, infoString) {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;
  this->ui = ui;
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }
