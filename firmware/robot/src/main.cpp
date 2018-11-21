<<<<<<< HEAD
#include "HTTP/Request.hpp"
#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"
#include "HTTP/WebServer.hpp"
#include "DB/DB.hpp"

class TestRoute : public Route {
 public:
  TestRoute() : Route("/test", "GET") {}
  void handle(const Request *request, Response *response) override {
    response->json("{value:0}");
  }
};

class EchoRoute : public Route {
 public:
  EchoRoute() : Route("/echo", "GET") {}
  void handle(const Request *request, Response *response) override {
    std::string tmp;
    tmp += "URL: " + request->url + '\n';
    tmp += "METHOD: " + request->method + '\n';
    tmp += "BODY: " + request->body + '\n';
    tmp += "QUERY: " + request->queryString + '\n';

    for (auto pair : request->headerFields) {
      tmp += "HEADER FIELD: " + pair.key + " = " + pair.value + '\n';
    }
    response->json(tmp.c_str());
  }
};

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
=======
#include "Comm.hpp"
#include "DB.hpp"
#include "RobotHardwareInterface.hpp"

int main() {
  DB db("test.db");
  RobotHardwareInterface robotHardwareInterface;

  Comm comm(&robotHardwareInterface);
  for (;;) {
    comm.poll();
    robotHardwareInterface.poll();
  }
}
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
