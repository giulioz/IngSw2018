#include "Comm.hpp"

Comm::Comm() : server(), webApi(&server), pairing(&server) {}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }

void Comm::start() {
  for (;;) {
    this->poll();
  }
}
