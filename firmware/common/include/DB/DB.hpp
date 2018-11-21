#pragma once

#include <unqlite.h>
#include <array>

class DB {
 private:
  unqlite* pDb;

 public:
  DB(const char* dbFile);
  ~DB();

  void storeValue(const char* key, const void* data, unqlite_int64 dataLength);
  void appendValue(const char* key, const void* data, unqlite_int64 dataLength);
  bool deleteValue(const char* key);
  template <typename T, size_t s>
  bool fetchValue(const char* key, std::array<T, s> buffer);
  // bool fetchValueAsync(const char* key);
};
