#include "Network/Request.hpp"

#include <vector>

std::vector<std::string> tokenize(const std::string& s, char c) {
  auto end = s.cend();
  auto start = end;

  std::vector<std::string> vec;
  for (auto it = s.cbegin(); it != end; ++it) {
    if (*it != c) {
      if (start == end) start = it;
      continue;
    }
    if (start != end) {
      vec.emplace_back(start, it);
      start = end;
    }
  }
  if (start != end) vec.emplace_back(start, end);
  return vec;
}

Request::Request(struct http_message* hm) {
  if (hm->uri.p) {
    std::string tmp(hm->uri.p);
    this->url += tmp.substr(0, hm->uri.len);
  }

  if (hm->method.p) {
    std::string tmp(hm->method.p);
    this->method += tmp.substr(0, hm->method.len);
  }

  if (hm->body.p) {
    std::string tmp(hm->body.p);
    this->body += tmp.substr(0, hm->body.len);
  }

  if (hm->query_string.p) {
    std::string tmp(hm->query_string.p);
    std::string queryString = tmp.substr(0, hm->query_string.len);
    auto queries = tokenize(queryString, '&');
    for (auto query : queries) {
      auto kv = tokenize(query, '=');
      if (kv.size() >= 2) {
        queryParams.insert(std::pair<std::string, std::string>(kv[0], kv[1]));
      }
    }
  }

  urlParams = tokenize(this->url, '/');

  for (size_t i = 0; hm->header_names[i].p; i++) {
    std::string tmpN(hm->header_names[i].p);
    std::string tmpV(hm->header_values[i].p);
    headerFields.insert(std::pair<std::string, std::string>(
        tmpN.substr(0, hm->header_names[i].len),
        tmpV.substr(0, hm->header_values[i].len)));
  }
}

Request::~Request() {}
