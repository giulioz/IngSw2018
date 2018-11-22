#include "WebApi.hpp"

void WebApi::getIntrusions(const Request *request, Response *response) {
  response->json(
      "[{id:0, time:0, readt:true}, {id:1, time:1, readt:true}, {id:3, time:3, "
      "readt:false}]");
}

void WebApi::getIntrusionsUnread(const Request *request, Response *response) {
  response->json("[{id:3, time:3, readt:false}]");
}

void WebApi::getIntrusionsTime(const Request *request, Response *response) {
  response->json("[{id:1, time:1, readt:true}]");
}

void WebApi::getIntrusionShoot(const Request *request, Response *response) {
  auto imgData = this->imageCapturer->captureJpeg();
  response->type("image/jpeg");
  response->send(imgData.data(), imgData.size());
}

void WebApi::getShoot(const Request *request, Response *response) {
  auto imgData = this->imageCapturer->captureJpeg();
  response->type("image/jpeg");
  response->send(imgData.data(), imgData.size());
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

void WebApi::getInfo(const Request *request, Response *response) {
  response->json(this->infoString);
}

void getTest(const Request *request, Response *response) {
  std::string tmp;
  tmp += "URL: " + request->url + '\n';
  tmp += "METHOD: " + request->method + '\n';
  tmp += "BODY: " + request->body + '\n';
  for (auto pair : request->queryParams) {
    tmp += "QUERY FIELD: " + pair.first + " = " + pair.second + '\n';
  }
  for (auto pair : request->headerFields) {
    tmp += "HEADER FIELD: " + pair.first + " = " + pair.second + '\n';
  }
  response->json(tmp.c_str());
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

  webServer.addRoute("/intrusions/:id/shoot", "GET",
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

  webServer.addRoute("/info", "GET",
                     [this](const Request *request, Response *response) {
                       this->getInfo(request, response);
                     });

  webServer.addRoute("/test", "GET",
                     [this](const Request *request, Response *response) {
                       this->getTest(request, response);
                     });
}

WebApi::WebApi(Server *server, HardwareInterface *hardwareInterface,
               ImageCapturer *imageCapturer, const char *infoString)
    : webServer(server, "0.0.0.0:8000") {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;
  this->infoString = infoString;
  this->loadRoutes();
}
