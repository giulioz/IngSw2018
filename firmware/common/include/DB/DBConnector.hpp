#pragma once

#include <unqlite.h>
#include <array>
#include <exception>

class DBConnector {
 private:
  unqlite* pDb;

 public:
  DBConnector(const char* dbFile);
  ~DBConnector();

  template <typename T>
  void storeValue(const char* key, const T* buf, unqlite_int64 len) {
    if (unqlite_kv_store(pDb, key, -1, buf,
                         static_cast<unqlite_int64>(sizeof(T) * len)) !=
        UNQLITE_OK) {
      throw std::runtime_error("Cannot store value.");
    }
  }

  template <typename T>
  void appendValue(const char* key, const T* buf, unqlite_int64 len) {
    if (unqlite_kv_append(pDb, key, -1, buf,
                          static_cast<unqlite_int64>(sizeof(T) * len)) !=
        UNQLITE_OK) {
      throw std::runtime_error("Cannot append value.");
    }
  }

  void deleteValue(const char* key);
  void deleteAll();

  template <typename T>
  bool fetchValue(const char* key, T* buf, unqlite_int64 len) {
    unqlite_int64 length = static_cast<unqlite_int64>(sizeof(T) * len);
    return (unqlite_kv_fetch(pDb, key, -1, buf, &length) == UNQLITE_OK);
  }

  // bool fetchValueAsync(const char* key);
};
