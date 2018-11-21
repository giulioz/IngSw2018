#include "Network/UDPData.hpp"

#include <cstring>

UDPData::UDPData(char* data, int size, ServerUDP* server,
                 struct mg_connection* connection) {
  this->data = new char[size];
  this->size = size;
  this->server = server;
  this->connection = connection;
  memcpy(this->data, data, size);
}

UDPData::~UDPData() { delete data; }

void UDPData::reply(const char* data, int size) {
  mg_send(connection, data, size);
}
