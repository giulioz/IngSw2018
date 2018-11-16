#include "HTTP/Route.hpp"
#include <string>

Route::Route(const char *path, const char *method) {
  this->path = path;
  this->method = method;
}

Route::~Route() {}

static bool _match(const char *path, const char *toMatch);

static bool _matchParam(const char *path, const char *toMatch) {
  while (*toMatch != '/' && *toMatch) {
    toMatch++;
  }

  while (*path != '/' && *path) {
    path++;
  }

  return _match(path, toMatch);
}

static bool _match(const char *path, const char *toMatch) {
  if (!*path && !*toMatch) {
    return true;
  } else if (!*path && *toMatch) {
    return false;
  } else if (*path && !*toMatch) {
    return true;
  } else if (*toMatch == ':') {
    return _matchParam(path, toMatch);
  } else if (*path == *toMatch) {
    return _match(path + 1, toMatch + 1);
  }
}

bool Route::match(const char *path, const char *method) {
  return (_match(path, this->path) || strcmp("*", this->method) == 0) &&
         (strcmp(method, this->method) == 0 || strcmp("*", this->method) == 0);
}

void Route::handle(Response *response) {}
