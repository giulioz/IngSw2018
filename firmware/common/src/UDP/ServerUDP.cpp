#include "UDP/ServerUDP.hpp"

static void wrapperHandler(struct mg_connection *nc, int ev, void *p) {
  ServerUDP *_this = static_cast<ServerUDP *>(nc->user_data);
  _this->handler(nc, ev, p);
}

ServerUDP::ServerUDP(Server *server, const char *address) {
  this->server = server;
  this->nc = server->bind(address, wrapperHandler, this);
}

ServerUDP::~ServerUDP() {}

void ServerUDP::handler(struct mg_connection *c, int ev, void *p) {
  struct mbuf *io = &c->recv_mbuf;
  if (ev == MG_EV_RECV) {
    mg_send(c, io->buf, io->len);
    mbuf_remove(io, io->len);  // Pulisce il buffer
  }
}
