#include <mongoose.h>
#include <Server.hpp>

class ServerUDP {
 private:
  Server *server;
  struct mg_connection *nc;

 public:
  ServerUDP(Server *server, const char *address);
  ~ServerUDP();
  void handler(struct mg_connection *nc, int ev, void *p);
};
