#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"
#include "HTTP/WebServer.hpp"

#include <mongoose.h>
#include <stdio.h>

int main() {
  WebServer webServer("0.0.0.0:8000");
  webServer.start();
}
