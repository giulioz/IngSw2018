#include "HTTP/NotFoundRoute.hpp"

NotFoundRoute::NotFoundRoute() : Route("*", "*") {}

void NotFoundRoute::handle(const Request *request, Response *response) {
  response->sendStatus(404);
}
