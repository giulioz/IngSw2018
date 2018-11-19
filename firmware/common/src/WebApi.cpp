#include "WebApi.hpp"

void WebApi::postPair(const Request *request, Response *response){
  response->json("{value:0}");
}

WebApi::WebApi(Server *server) : webServer(server, "0.0.0.0:8000") {
  // webServer.addRoute("/pair", "POST", postPair);

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
