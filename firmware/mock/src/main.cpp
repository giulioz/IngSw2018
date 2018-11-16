#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"
#include "HTTP/WebServer.hpp"

class TestRoute : public Route {
 public:
  TestRoute() : Route("/test", "GET") {}
  void handle(Response *response) override {
    response->json("{value:0}");
  }
};

int main() {
  WebServer webServer("0.0.0.0:8000");

  TestRoute testRoute;
  webServer.addRoute(static_cast<Route*>(&testRoute));

  webServer.start();
}
