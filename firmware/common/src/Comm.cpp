#include "Comm.hpp"

Comm::Comm(HardwareInterface *hardwareInterface)
    : server(), webApi(&server, hardwareInterface), pairing(&server) {
  this->hardwareInterface = hardwareInterface;
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }
