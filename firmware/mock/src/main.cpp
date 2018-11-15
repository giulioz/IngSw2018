#include "HTTP/WebServer.hpp"

int main() {
  WebServer webServer("0.0.0.0:8000");
  webServer.start();
}
