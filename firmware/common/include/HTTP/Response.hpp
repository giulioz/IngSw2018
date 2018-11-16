#pragma once

#include <mongoose.h>

class Response {
 private:
  bool statusSent;
  bool typeSent;

 public:
  struct mg_connection *connection;
  Response(struct mg_connection *connection);
  virtual ~Response();

  void type(const char* mimeType);
  void append(const char* field, const char* value);
  void status(int statusCode);
  void send(const void* content, long size);
  void send(const char* content);
  void json(const char* content);
  void sendStatus(int statusCode);
};
