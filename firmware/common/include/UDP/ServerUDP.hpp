#include <mongoose.h>

class ServerUDP {
 private:
  mg_mgr mgr;
  struct mg_connection *nc;

 public:
  ServerUDP(const char *address);
  ~ServerUDP();
  void start();
  void handler(struct mg_connection *nc, int ev, void *p);
};
