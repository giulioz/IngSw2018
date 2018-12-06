#include "WebApi.hpp"

void WebApi::getAlarmStatus(const Request *request, Response *response) {
  response->json("[{id:3, time:3, readt:false}]");
}

void WebApi::getAutoConf(const Request *request, Response *response) {
  response->json("[{id:3, time:3, readt:false}]");
}

void WebApi::postAlarmOn(const Request *request, Response *response) {
  response->json("[{id:3, time:3, readt:false}]");
}

void WebApi::postAlarmOff(const Request *request, Response *response) {
  response->json("[{id:3, time:3, readt:false}]");
}

void WebApi::postAutoToggle(const Request *request, Response *response) {
  response->json("[{id:3, time:3, readt:false}]");
}

void WebApi::postAutoConf(const Request *request, Response *response) {
  response->json("[{id:3, time:3, readt:false}]");
}

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

void WebApi::getTest(const Request *request, Response *response) {
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

#define ROUTE(path, method, function)                                     \
  webServer.addRoute(path, method,                                        \
                     [this](const Request *request, Response *response) { \
                       this->function(request, response);                 \
                     });

void WebApi::loadRoutes() {
  ROUTE("/alarm/status", "GET", getAlarmStatus);
  ROUTE("/auto/conf", "GET", getAutoConf);
  ROUTE("/alarm/on", "POST", postAlarmOn);
  ROUTE("/alarm/off", "POST", postAlarmOff);
  ROUTE("/auto/toggle", "POST", postAutoToggle);
  ROUTE("/auto/conf", "POST", postAutoConf);
  ROUTE("/intrusions/unread", "GET", getIntrusionsUnread);
  ROUTE("/intrusions/time/:start/:end", "GET", getIntrusionsTime);
  ROUTE("/intrusions/:id/shoot", "GET", getIntrusionShoot);
  ROUTE("/intrusions", "GET", getIntrusions);
  ROUTE("/shoot", "GET", getShoot);
  ROUTE("/move/left", "POST", postLeft);
  ROUTE("/move/right", "POST", postRight);
  ROUTE("/pair", "POST", postPair);
  ROUTE("/info", "GET", getInfo);
  ROUTE("/test", "GET", getTest);
}

WebApi::WebApi(Server *server, HardwareInterface *hardwareInterface,
               ImageCapturer *imageCapturer, const char *infoString)
    : webServer(server, "0.0.0.0:8000") {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;
  this->infoString = infoString;
  this->loadRoutes();
}
