#include "HTTP/NotFoundRoute.hpp"

NotFoundRoute::NotFoundRoute() : Route("*", "*") {}

void NotFoundRoute::handle(Response *res) {
  mg_printf(res->connection, "%s",
            "HTTP/1.0 404 Not Found\r\n"
            "Content-Length: 0\r\n\r\n");
}
