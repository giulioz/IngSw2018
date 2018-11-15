#include "HTTP/Route.hpp"
#include "HTTP/WebServer.hpp"

#include <stdio.h>

class TestRoute : public Route {
 public:
  TestRoute() : Route("/test") {}

  void handle() { printf("test lol\n"); }
};

int main() {
  TestRoute testRoute;

  WebServer webServer("0.0.0.0:8000");
  webServer.addRoute(static_cast<Route*>(&testRoute));
  webServer.start();
}
