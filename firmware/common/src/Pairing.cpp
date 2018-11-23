#include "Pairing.hpp"

#include <string>

Pairing::Pairing(Server *server, const char *info)
    : serverUdp(server, "udp://0.0.0.0:8001", [info](UDPData *data) {
        if (strcmp(data->data, "DOGE_SEARCH\n") == 0) {
          std::string tmp;
          tmp += "DOGE_ANNOUNCE;";
          tmp += info;
          data->reply(tmp.c_str(), tmp.length());
        }
      }) {
  this->server = server;
}

Pairing::~Pairing() {}
