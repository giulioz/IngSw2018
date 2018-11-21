<<<<<<< HEAD
#include "Comm.hpp"

#include <time.h>

Comm::Comm() : server(), webServer(&server, "0.0.0.0:8000"), pairing(&server) {
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
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }

void Comm::start() {
  for (;;) {
    this->poll();
  }
}
=======
#include "Comm.hpp"

Comm::Comm(HardwareInterface *hardwareInterface)
    : server(), webApi(&server, hardwareInterface), pairing(&server) {
  this->hardwareInterface = hardwareInterface;
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
