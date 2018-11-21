#include "Pairing.hpp"

#include <string>

Pairing::Pairing(Server *server) : serverUdp(server, "udp://0.0.0.0:8001") {
  this->server = server;

  serverUdp.setEventHandler([](UDPData *data) {
    if (data->data == "DOGE_SEARCH") {
      std::string tmp;
      tmp += "DOGE_ANNOUNCE";
      data->reply(tmp.c_str(), tmp.length());
    }
  });
}

Pairing::~Pairing() {}
