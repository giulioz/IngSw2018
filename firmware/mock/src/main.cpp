#include "HTTP/Request.hpp"
#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"
#include "HTTP/WebServer.hpp"

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
    tmp += "URL:";
    tmp += request->url + '\n';
    tmp += "METHOD:";
    tmp += request->method + '\n';
    tmp += "BODY:";
    tmp += request->body + '\n';
    tmp += "QUERY:";
    tmp += request->queryString + '\n';
    response->json(tmp.c_str());
  }
};

int main() {
  Server server;
  WebServer webServer(&server, "0.0.0.0:8000");

  TestRoute testRoute;
  webServer.addRoute(static_cast<Route *>(&testRoute));

  EchoRoute echoRoute;
  webServer.addRoute(static_cast<Route *>(&echoRoute));

  server.start();
}
