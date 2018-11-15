#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"
#include "HTTP/WebServer.hpp"

#include <mongoose.h>
#include <stdio.h>

class ErrorRoute : public Route {
 public:
  ErrorRoute() : Route("") {}

  void handle(Response *res) {
    mg_printf(res->connection, "%s",
              "HTTP/1.0 404 Not Found\r\n"
              "Content-Length: 0\r\n\r\n");
  }
};

int main() {
  ErrorRoute errorRoute;

  WebServer webServer("0.0.0.0:8000");
  webServer.addRoute(static_cast<Route *>(&errorRoute));
  webServer.start();
}
