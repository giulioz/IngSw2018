#include "WebApi.hpp"

WebApi::WebApi(Server *server, HardwareInterface *hardwareInterface)
    : webServer(server, "0.0.0.0:8000") {
  this->hardwareInterface = hardwareInterface;

  webServer.addRoute("/shoot", "GET",
                     [this](const Request *request, Response *response) {
                       response->json("{value:0}");
                     });

  webServer.addRoute("/move/left", "POST",
                     [this](const Request *request, Response *response) {
                       this->hardwareInterface->left();
                       response->sendStatus(200);
                     });

  webServer.addRoute("/move/right", "POST",
                     [this](const Request *request, Response *response) {
                       this->hardwareInterface->right();
                       response->sendStatus(200);
                     });

  webServer.addRoute("/pair", "POST",
                     [this](const Request *request, Response *response) {
                       response->json("{value:0}");
                     });

  webServer.addRoute("/test", "GET",
                     [this](const Request *request, Response *response) {
                       response->json("{value:0}");
                     });

  webServer.addRoute(
      "/echo", "GET", [this](const Request *request, Response *response) {
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
