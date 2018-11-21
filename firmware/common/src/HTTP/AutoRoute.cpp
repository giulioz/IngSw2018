<<<<<<< HEAD
#include "HTTP/AutoRoute.hpp"

AutoRoute::AutoRoute(const char *path, const char *method,
                     void (*handler)(const Request *request,
                                     Response *response))
    : Route(path, method) {
  this->handler = handler;
}

void AutoRoute::handle(const Request *request, Response *response) {
  this->handler(request, response);
}
=======
#include "HTTP/AutoRoute.hpp"

AutoRoute::AutoRoute(
    const char *path, const char *method,
    std::function<void(const Request *request, Response *response)> handler)
    : Route(path, method) {
  this->handler = handler;
}

void AutoRoute::handle(const Request *request, Response *response) {
  this->handler(request, response);
}
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
