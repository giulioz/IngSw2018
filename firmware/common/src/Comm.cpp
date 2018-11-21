<<<<<<< HEAD
#include "Comm.hpp"

Comm::Comm(HardwareInterface *hardwareInterface)
    : server(), webApi(&server, hardwareInterface), pairing(&server) {
  this->hardwareInterface = hardwareInterface;
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }
<<<<<<< HEAD
=======

void Comm::start() {
  for (;;) {
    this->poll();
  }
}
=======
#include "Comm.hpp"

Comm::Comm(HardwareInterface *hardwareInterface)
    : server(), webApi(&server, hardwareInterface), pairing(&server) {
  this->hardwareInterface = hardwareInterface;
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
>>>>>>> asdf
