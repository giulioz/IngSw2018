<<<<<<< HEAD
=======
<<<<<<< HEAD
#pragma once

#include "HTTP/WebServer.hpp"
#include "Server.hpp"
#include "UDP/ServerUDP.hpp"
#include "UDP/UDPData.hpp"
#include "Pairing.hpp"

class Comm {
 private:
 public:
  Server server;
  WebServer webServer;
  Pairing pairing;

  Comm();
  ~Comm();

  void poll();
  void start();
};
=======
>>>>>>> asdf
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
<<<<<<< HEAD
=======
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
>>>>>>> asdf
