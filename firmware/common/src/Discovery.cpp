#include "Discovery.hpp"

#include <string>

Discovery::Discovery(Server *server, const char *info)
    : serverUdp(server, "udp://0.0.0.0:8001", [info](UDPData *data) {
        if (memcmp(data->data, "DOGE_SEARCH", 11) == 0) {
          std::string tmp;
          tmp += "DOGE_ANNOUNCE;";
          tmp += info;
          data->reply(tmp.c_str(), tmp.length());
        }
      }) {
  this->server = server;
}

Discovery::~Discovery() {}
