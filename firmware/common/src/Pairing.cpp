<<<<<<< HEAD
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
=======
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
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
