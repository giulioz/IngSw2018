#include "Network/AutoRoute.hpp"

AutoRoute::AutoRoute(
    const char *path, const char *method,
    std::function<void(const Request *request, Response *response)> handler)
    : Route(path, method) {
  this->handler = handler;
}

void AutoRoute::handle(const Request *request, Response *response) {
  this->handler(request, response);
}
