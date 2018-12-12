#include "WebApi.hpp"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
using json = nlohmann::json;

/* ==================================
    Alarm
  ================================== */

void WebApi::getAlarmStatus(const Request *request, Response *response) {
  std::string json;
  json += "{active:";
  json += alarmEngine->active ? "true" : "false";
  json += ", auto:";
  json += alarmEngine->autoActivated ? "true" : "false";
  json += "}";

  response->json(json.c_str());
}

void WebApi::getAutoConf(const Request *request, Response *response) {
  // TODO in the future
  response->sendStatus(404);
}

void WebApi::postAlarmOn(const Request *request, Response *response) {
  alarmEngine->setAlarmState(true);
  response->sendStatus(200);
}

void WebApi::postAlarmOff(const Request *request, Response *response) {
  alarmEngine->setAlarmState(false);
  response->sendStatus(200);
}

void WebApi::postAutoToggle(const Request *request, Response *response) {
  // alarmEngine->setAutoState(true);
  // response->sendStatus(200);
  response->sendStatus(404);
}

void WebApi::postAutoConf(const Request *request, Response *response) {
  // TODO in the future
  response->sendStatus(404);
}

/* ==================================
    Intrusions
  ================================== */

void WebApi::getIntrusions(const Request *request, Response *response) {
  std::string json = "[";

  bool first = true;
  for (auto &&intrusion : root->getIntrusions()) {
    if (!first) {
      json += ",";
    } else {
      first = false;
    }
    json += intrusion.toString();

    intrusion.notified = true;
  }

  json += "]";

  this->db->store(*root);

  response->json(json.c_str());
}

void WebApi::getIntrusionsUnread(const Request *request, Response *response) {
  std::string json = "[";

  bool first = true;
  for (auto &&intrusion : root->getIntrusions()) {
    if (!intrusion.notified) {
      if (!first) {
        json += ",";
      } else {
        first = false;
      }
      json += intrusion.toString();

      intrusion.notified = true;
    }
  }

  json += "]";

  this->db->store(*root);

  response->json(json.c_str());
}

void WebApi::getIntrusionsTime(const Request *request, Response *response) {
  response->sendStatus(404);
}

static std::vector<char> readAllBytes(std::string filename) {
  std::ifstream ifs(filename, std::ios::binary | std::ios::ate);
  std::ifstream::pos_type pos = ifs.tellg();

  std::vector<char> result(pos);

  ifs.seekg(0, std::ios::beg);
  ifs.read(&result[0], pos);

  return result;
}

void WebApi::getIntrusionShoot(const Request *request, Response *response) {
  std::string fileName = "intrusion_";
  fileName += request->urlParams[1];
  fileName += ".jpg";

  auto bytes = readAllBytes(fileName);
  response->type("image/jpeg");
  response->send(bytes.data(), bytes.size());
}

/* ==================================
    Hardware
  ================================== */

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

/* ==================================
    Auth
  ================================== */

static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

static const char num[] = "0123456789";

static std::string genKey(int len, const char *table, int tSize) {
  std::string str;
  for (int i = 0; i < len; ++i) {
    str += table[rand() % (tSize - 1)];
  }
  return str;
}

void WebApi::getPair(const Request *request, Response *response) {
  auto clientKey = genKey(10, alphanum, sizeof(alphanum) - 1);
  auto pairKey = genKey(4, num, sizeof(num) - 1);
  authPairs[clientKey] = pairKey;

  ui->clear();
  ui->drawText(0, 0, pairKey.c_str());

  std::string json = "\"";
  json += clientKey;
  json += "\"";
  response->json(json.c_str());
}

void WebApi::postPair(const Request *request, Response *response) {
  auto inputJson = json::parse(request->body);
  auto clientKey = inputJson["clientKey"].get<std::string>();
  auto pairKey = inputJson["pairKey"].get<std::string>();

  auto pairEntry = authPairs[clientKey];
  if (pairEntry == pairKey) {
    auto authKey = genKey(20, alphanum, sizeof(alphanum) - 1);
    root->getAuthKeys()[clientKey] = authKey;
    db->store(*root);

    std::string json = "\"";
    json += clientKey;
    json += "\"";
    response->json(json.c_str());
  } else {
    response->sendStatus(403);
  }

  ui->clear();
  authPairs.erase(pairKey);
}

/* ==================================
    Misc
  ================================== */

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
  ROUTE("/pair", "GET", getPair);
  ROUTE("/pair", "POST", postPair);
  ROUTE("/info", "GET", getInfo);
  ROUTE("/test", "GET", getTest);
}

WebApi::WebApi(Server *server, HardwareInterface *hardwareInterface,
               AlarmEngine *alarmEngine, UI *ui, ImageCapturer *imageCapturer,
               DB *db, Root *root, const char *infoString)
    : webServer(server, "0.0.0.0:8000") {
  this->hardwareInterface = hardwareInterface;
  this->alarmEngine = alarmEngine;
  this->imageCapturer = imageCapturer;
  this->db = db;
  this->root = root;
  this->ui = ui;
  this->infoString = infoString;
  this->loadRoutes();
}
