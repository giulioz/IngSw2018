#include "DB/DBConnector.hpp"

DBConnector::DBConnector(const char* dbFile) {
  if (unqlite_open(&pDb, dbFile, UNQLITE_OPEN_CREATE) != UNQLITE_OK) {
    throw "Cannot open connection to DB.";
  }
}

DBConnector::~DBConnector() { unqlite_close(pDb); }

template <typename T>
void DBConnector::storeValue(const char* key, const T* buf, unqlite_int64 len) {
  if (unqlite_kv_store(pDb, key, -1, buf, (unqlite_int64)sizeof(T) * len) !=
      UNQLITE_OK) {
    throw "Cannot store value.";
  }
}

template <typename T>
void DBConnector::appendValue(const char* key, const T* buf,
                              unqlite_int64 len) {
  if (unqlite_kv_append(pDb, key, -1, buf, (unqlite_int64)sizeof(T) * len) !=
      UNQLITE_OK) {
    throw "Cannot append value.";
  }
}

void DBConnector::deleteValue(const char* key) {
  unqlite_kv_delete(pDb, key, -1);
}

void DBConnector::deleteAll() {
  int rc;
  unqlite_kv_cursor* pCursor;
  rc = unqlite_kv_cursor_init(pDb, &pCursor);
  for (unqlite_kv_cursor_first_entry(pCursor);
       unqlite_kv_cursor_valid_entry(pCursor);
       unqlite_kv_cursor_next_entry(pCursor)) {
    rc = unqlite_kv_cursor_delete_entry(pCursor);
  }
}

template <typename T>
bool DBConnector::fetchValue(const char* key, const T* buf, unqlite_int64 len) {
  return (unqlite_kv_fetch(pDb, key, -1, buf, (unqlite_int64)sizeof(T) * len) ==
          UNQLITE_OK);
}

// bool DBConnector::fetchValueAsync(const char* key) {
//   if (unqlite_kv_store(pDb, key, -1) != UNQLITE_OK) {
//     throw "Cannot store value.";
//   }
// }
