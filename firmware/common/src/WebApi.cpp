#include "WebApi.hpp"

void WebApi::getIntrusions(const Request *request, Response *response) {
  response->json("[{id:0, time:0}, {id:1, time:1}]");
}

void WebApi::getIntrusionsUnread(const Request *request, Response *response) {
  response->json("[]");
}

void WebApi::getIntrusionsTime(const Request *request, Response *response) {
  response->json("[{id:1, time:1}]");
}

void WebApi::getIntrusionShoot(const Request *request, Response *response) {
  response->send(nullptr, 0);
}

void WebApi::getShoot(const Request *request, Response *response) {
  response->send(nullptr, 0);
}

void WebApi::postLeft(const Request *request, Response *response) {
  this->hardwareInterface->left();
  response->sendStatus(200);
}

void WebApi::postRight(const Request *request, Response *response) {
  this->hardwareInterface->right();
  response->sendStatus(200);
}

void WebApi::postPair(const Request *request, Response *response) {
  response->json("");
}

void WebApi::deletePair(const Request *request, Response *response) {
  response->sendStatus(200);
}

void WebApi::getInfo(const Request *request, Response *response) {
  response->json(this->infoString);
}

void WebApi::loadRoutes() {
  webServer.addRoute("/intrusions/unread", "GET",
                     [this](const Request *request, Response *response) {
                       this->getIntrusionsUnread(request, response);
                     });

  webServer.addRoute("/intrusions/time/:start/:end", "GET",
                     [this](const Request *request, Response *response) {
                       this->getIntrusionsTime(request, response);
                     });

  webServer.addRoute("/intrusions/shoot/:id", "GET",
                     [this](const Request *request, Response *response) {
                       this->getIntrusionShoot(request, response);
                     });

  webServer.addRoute("/intrusions", "GET",
                     [this](const Request *request, Response *response) {
                       this->getIntrusions(request, response);
                     });

  webServer.addRoute("/shoot", "GET",
                     [this](const Request *request, Response *response) {
                       this->getShoot(request, response);
                     });

  webServer.addRoute("/move/left", "POST",
                     [this](const Request *request, Response *response) {
                       this->postLeft(request, response);
                     });

  webServer.addRoute("/move/right", "POST",
                     [this](const Request *request, Response *response) {
                       this->postRight(request, response);
                     });

  webServer.addRoute("/pair", "POST",
                     [this](const Request *request, Response *response) {
                       this->postPair(request, response);
                     });

  webServer.addRoute("/pair", "DELETE",
                     [this](const Request *request, Response *response) {
                       this->deletePair(request, response);
                     });

  webServer.addRoute("/info", "GET",
                     [this](const Request *request, Response *response) {
                       this->getInfo(request, response);
                     });
}

WebApi::WebApi(Server *server, HardwareInterface *hardwareInterface,
               const char *infoString)
    : webServer(server, "0.0.0.0:8000") {
  this->hardwareInterface = hardwareInterface;
  this->infoString = infoString;
  this->loadRoutes();
}
