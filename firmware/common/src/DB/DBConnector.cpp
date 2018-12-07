#include "DB/DBConnector.hpp"

#include <exception>

DBConnector::DBConnector(const char* dbFile) {
  if (unqlite_open(&pDb, dbFile, UNQLITE_OPEN_CREATE) != UNQLITE_OK) {
    throw std::runtime_error("Cannot open connection to DB.");
  }
}

DBConnector::~DBConnector() { unqlite_close(pDb); }

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

// bool DBConnector::fetchValueAsync(const char* key) {
//   if (unqlite_kv_store(pDb, key, -1) != UNQLITE_OK) {
//     throw "Cannot store value.";
//   }
// }
