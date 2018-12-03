#pragma once

#include <unqlite.h>
#include <array>

class DBConnector {
 private:
  unqlite* pDb;

 public:
  DBConnector(const char* dbFile);
  ~DBConnector();

  template <typename T>
  void storeValue(const char* key, const T* buf, unqlite_int64 len);
  template <typename T>
  void appendValue(const char* key, const T* buf, unqlite_int64 len);
  void deleteValue(const char* key);
  void deleteAll();
  template <typename T>
  bool fetchValue(const char* key, const T* buf, unqlite_int64 len);
  // bool fetchValueAsync(const char* key);
};
