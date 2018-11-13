#include "WebServer.hpp"

static void wrapperHandler(struct mg_connection *nc, int ev, void *p) {
  WebServer *_this = static_cast<WebServer *>(nc->user_data);
  _this->handler(nc, ev, p);
}

WebServer::WebServer(const char *address) {
  mg_mgr_init(&mgr, this);
  nc = mg_bind(&mgr, address, wrapperHandler);

  mg_set_protocol_http_websocket(nc);
  httpServerOpts.document_root = ".";
  httpServerOpts.enable_directory_listing = "yes";
}

WebServer::~WebServer() { mg_mgr_free(&mgr); }

void WebServer::start() {
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
}

void WebServer::handler(struct mg_connection *nc, int ev, void *p) {
  if (ev == MG_EV_HTTP_REQUEST) {
    mg_serve_http(nc, (struct http_message *)p, httpServerOpts);
  }
}
