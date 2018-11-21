#include "Pairing.hpp"

#include <string>

Pairing::Pairing(Server *server) : serverUdp(server, "udp://0.0.0.0:8001") {
  this->server = server;

  serverUdp.setEventHandler([](UDPData *data) {
    std::string tmp;
    tmp += "Time: ";
    tmp += std::to_string(time(nullptr));
    data->reply(tmp.c_str(), tmp.size());
  });
}

Pairing::~Pairing() {}
