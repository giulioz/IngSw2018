#include "HTTP/NotFoundRoute.hpp"

NotFoundRoute::NotFoundRoute() : Route("*", "*") {}

void NotFoundRoute::handle(Response *res) {
  res->sendStatus(404);
}
