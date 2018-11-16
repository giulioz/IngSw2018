#include "HTTP/WebServer.hpp"

static void wrapperHandler(struct mg_connection *nc, int ev, void *p) {
  WebServer *_this = static_cast<WebServer *>(nc->mgr->user_data);
  _this->handler(nc, ev, p);
}

WebServer::WebServer(const char *address) {
  mg_mgr_init(&mgr, this);
  this->nc = mg_bind(&mgr, address, wrapperHandler);

  mg_set_protocol_http_websocket(this->nc);

  this->addRoute(static_cast<Route *>(&this->notFoundRoute));
}

WebServer::~WebServer() { mg_mgr_free(&mgr); }

void WebServer::start() {
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
}

void WebServer::handler(struct mg_connection *c, int ev, void *p) {
  if (ev == MG_EV_HTTP_REQUEST) {
    struct http_message *hm = static_cast<struct http_message *>(p);

    for (auto route : routes) {
      if (route->match(hm->uri.p, hm->method.p)) {
        Response response(c);
        route->handle(&response);
        break;
      }
    }
  }
}

void WebServer::addRoute(Route *route) { this->routes.push_back(route); }
