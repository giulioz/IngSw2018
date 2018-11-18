#include "Comm.hpp"

TestRoute::TestRoute() : Route("/test", "GET") {}
void TestRoute::handle(const Request *request, Response *response) {
  response->json("{value:0}");
}

EchoRoute::EchoRoute() : Route("/echo", "GET") {}
void EchoRoute::handle(const Request *request, Response *response) {
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

Comm::Comm()
    : server(),
      webServer(&server, "0.0.0.0:8000"),
      serverUdp(&server, "udp://0.0.0.0:8001") {
  webServer.addRoute(static_cast<Route *>(&testRoute));
  webServer.addRoute(static_cast<Route *>(&echoRoute));
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }

void Comm::start() { server.start(); }
