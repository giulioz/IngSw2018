#pragma once

class Route {
 private:
  const char *path;

 public:
  Route(const char *path);
  virtual ~Route();

  bool match(const char *path);
  virtual void handle() = 0;
};
