#pragma once

#include <mongoose.h>

class ServerUDP;

class UDPData {
 public:
  char* data;
  int size;
  ServerUDP* server;
  struct mg_connection* connection;

  UDPData(char* data, int size, ServerUDP* server,
          struct mg_connection* connection);
  ~UDPData();

  void reply(const char* data, int size);
};
