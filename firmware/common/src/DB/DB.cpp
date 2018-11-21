#include "DB/DB.hpp"

DB::DB(const char* dbFile) {
  if (unqlite_open(&pDb, dbFile, UNQLITE_OPEN_CREATE) != UNQLITE_OK) {
    throw "Cannot open DB.";
  }
}

DB::~DB() { unqlite_close(pDb); }

void DB::storeValue(const char* key, const void* data,
                    unqlite_int64 dataLength) {
  if (unqlite_kv_store(pDb, key, -1, data, dataLength) != UNQLITE_OK) {
    throw "Cannot store value.";
  }
}

void DB::appendValue(const char* key, const void* data,
                     unqlite_int64 dataLength) {
  if (unqlite_kv_append(pDb, key, -1, data, dataLength) != UNQLITE_OK) {
    throw "Cannot append value.";
  }
}

bool DB::deleteValue(const char* key) {
  return (unqlite_kv_delete(pDb, key, -1) == UNQLITE_OK);
}

template <typename T, size_t s>
bool DB::fetchValue(const char* key, std::array<T, s> buffer) {
  return (unqlite_kv_fetch(pDb, key, -1, buffer.data, buffer.size) ==
          UNQLITE_OK);
}

// bool DB::fetchValueAsync(const char* key) {
//   if (unqlite_kv_store(pDb, key, -1) != UNQLITE_OK) {
//     throw "Cannot store value.";
//   }
// }
