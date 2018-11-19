#include "Comm.hpp"

#include <time.h>

Comm::Comm()
    : server(),
      webServer(&server, "0.0.0.0:8000"),
      serverUdp(&server, "udp://0.0.0.0:8001") {
  webServer.addRoute("/test", "GET",
                     [](const Request *request, Response *response) {
                       response->json("{value:0}");
                     });

  webServer.addRoute(
      "/echo", "GET", [](const Request *request, Response *response) {
        std::string tmp;
        tmp += "URL: " + request->url + '\n';
        tmp += "METHOD: " + request->method + '\n';
        tmp += "BODY: " + request->body + '\n';
        tmp += "QUERY: " + request->queryString + '\n';

        for (auto pair : request->headerFields) {
          tmp += "HEADER FIELD: " + pair.key + " = " + pair.value + '\n';
        }
        response->json(tmp.c_str());
      });

  serverUdp.setEventHandler([](UDPData *data) {
    std::string tmp;
    tmp += "Time: ";
    tmp += std::to_string(time(nullptr));
    data->reply(tmp.c_str(), tmp.size());
  });
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }

void Comm::start() {
  for (;;) {
    this->poll();
  }
}
