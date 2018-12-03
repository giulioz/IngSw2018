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
  void storeAuthKeys(const Root&);
  void storeAutoModeConf(const Root&);
  void storeIntrusions(const Root&);

 public:
  DB(DBConnector*);

  Root fetch();
  void store(const Root&);
};
