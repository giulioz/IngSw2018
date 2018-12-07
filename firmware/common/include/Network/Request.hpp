#pragma once

#include <mongoose.h>
#include <map>
#include <string>
#include <vector>

class Request {
 private:
 public:
  std::string url;
  std::string method;
  std::string body;
  std::vector<std::string> urlParams;
  std::map<std::string, std::string> queryParams;
  std::map<std::string, std::string> headerFields;

  Request(struct http_message *hm);
  virtual ~Request();
};
