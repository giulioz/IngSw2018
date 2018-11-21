
#pragma once

#include "HardwareInterface.hpp"
#include "Pairing.hpp"
#include "Server.hpp"
#include "WebApi.hpp"

class Comm {
 private:
  HardwareInterface *hardwareInterface;

 public:
  Server server;
  WebApi webApi;
  Pairing pairing;

  Comm(HardwareInterface *hardwareInterface);
  ~Comm();

  void poll();
};
