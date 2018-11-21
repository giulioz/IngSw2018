#include "Comm.hpp"

Comm::Comm(HardwareInterface *hardwareInterface, const char *infoString)
    : server(),
      webApi(&server, hardwareInterface, infoString),
      pairing(&server) {
  this->hardwareInterface = hardwareInterface;
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }
