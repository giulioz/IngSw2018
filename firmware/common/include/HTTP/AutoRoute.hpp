<<<<<<< HEAD
#pragma once

#include "HTTP/Request.hpp"
#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"

class AutoRoute : public Route {
 private:
  void (*handler)(const Request *request, Response *response);

 public:
  AutoRoute(const char *path, const char *method,
            void (*handler)(const Request *request, Response *response));
  void handle(const Request *request, Response *response) override;
};
=======
#pragma once

#include "HTTP/Request.hpp"
#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"

#include <functional>

class AutoRoute : public Route {
 private:
  std::function<void(const Request *request, Response *response)> handler;

 public:
  AutoRoute(const char *path, const char *method,
            std::function<void(const Request *request, Response *response)> handler);
  void handle(const Request *request, Response *response) override;
};
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
