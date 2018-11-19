#include "Server.hpp"

Server::Server() { mg_mgr_init(&mgr, this); }

Server::~Server() { mg_mgr_free(&mgr); }

mg_connection *Server::bind(const char *address,
                            void (*handler)(struct mg_connection *nc, int ev,
                                            void *p),
                            void *ref) {
  struct mg_bind_opts opts = {0};
  opts.user_data = ref;
  return mg_bind_opt(&this->mgr, address, handler, opts);
}

void Server::poll() { mg_mgr_poll(&mgr, 1000); }
