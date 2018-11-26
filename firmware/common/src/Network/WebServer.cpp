#include "Network/WebServer.hpp"

static void wrapperHandler(struct mg_connection *nc, int ev, void *p) {
  WebServer *_this = static_cast<WebServer *>(nc->user_data);
  _this->handler(nc, ev, p);
}

WebServer::WebServer(Server *server, const char *address) : Router("") {
  this->server = server;
  this->nc = server->bind(address, wrapperHandler, this);

  mg_set_protocol_http_websocket(this->nc);
}

WebServer::~WebServer() {}

void WebServer::handler(struct mg_connection *c, int ev, void *p) {
  if (ev == MG_EV_HTTP_REQUEST) {
    auto hm = static_cast<struct http_message *>(p);
    Request request(hm);
    Response response(c);
    this->handle(&request, &response);
  }
}
