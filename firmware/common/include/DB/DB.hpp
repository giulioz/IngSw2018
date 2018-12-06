#pragma once

#include <list>
#include <map>
#include <string>
#include <vector>

#include "DB/DBConnector.hpp"
#include "DB/Entity/Intrusion.hpp"
#include "DB/Entity/Root.hpp"
#include "DB/Entity/Time.hpp"
#include "DB/Entity/TimeSpan.hpp"
#include "DB/Entity/WeekDay.hpp"

class DB {
 private:
  DBConnector* pDbC;

  void fetchAuthKeys(Root&);
  void fetchAutoModeConf(Root&);
  void fetchIntrusions(Root&);
  void storeAuthKeys(Root&);
  void storeAutoModeConf(Root&);
  void storeIntrusions(Root&);

 public:
  DB(DBConnector*);

  void fetch(Root& root);
  void store(Root&);
};
