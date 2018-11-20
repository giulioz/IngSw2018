#include "Comm.hpp"
#include "DB/DB.hpp"

int main() {
  DB db("test.db");

  Server server;
  WebServer webServer(&server, "0.0.0.0:8000");

  TestRoute testRoute;
  webServer.addRoute(static_cast<Route *>(&testRoute));
  EchoRoute echoRoute;
  webServer.addRoute(static_cast<Route *>(&echoRoute));

  server.start();
}
