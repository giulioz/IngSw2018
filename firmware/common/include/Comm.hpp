#pragma once

#include "Pairing.hpp"
#include "Server.hpp"
#include "WebApi.hpp"

class Comm {
 private:
 public:
  Server server;
  WebApi webApi;
  Pairing pairing;

  Comm();
  ~Comm();

  void poll();
  void start();
};
