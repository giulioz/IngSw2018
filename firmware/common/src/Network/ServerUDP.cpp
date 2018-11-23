#include "Network/ServerUDP.hpp"

static void wrapperHandler(struct mg_connection *connection, int ev, void *p) {
  ServerUDP *_this = static_cast<ServerUDP *>(connection->user_data);
  _this->handler(connection, ev, p);
}

ServerUDP::ServerUDP(Server *server, const char *address,
                     std::function<void(UDPData *data)> eventHandler) {
  this->server = server;
  this->eventHandler = eventHandler;
  this->connection = server->bind(address, wrapperHandler, this);
}

ServerUDP::~ServerUDP() {}

void ServerUDP::handler(struct mg_connection *connection, int ev, void *p) {
  if (ev == MG_EV_RECV) {
    struct mbuf *io = &connection->recv_mbuf;
    UDPData data(io->buf, io->len, this, connection);
    mbuf_remove(io, io->len);
    this->eventHandler(&data);
    connection->flags |= MG_F_SEND_AND_CLOSE;
  }
}
