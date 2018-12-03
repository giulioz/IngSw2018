#include "DB/DB.hpp"

DB::DB(DBConnector* pDbC) { this->pDbC = pDbC; }

void DB::fetchAuthKeys(Root& root) {
  long size;
  this->pDbC->fetchValue<long>("$ak", &size, 1);
  for (long i = 0; i < size; i++) {
    long size1;
    this->pDbC->fetchValue<long>(
        std::string("ak[" + std::to_string(i) + "].$k").c_str(), &size1, 1);
    std::vector<char> key(size1 + 1);
    this->pDbC->fetchValue<char>(
        std::string("ak[" + std::to_string(i) + "].k").c_str(), &key[0],
        size1 + 1);
    this->pDbC->fetchValue<long>(
        std::string("ak[" + std::to_string(i) + "].$v").c_str(), &size1, 1);
    std::vector<char> val(size1 + 1);
    this->pDbC->fetchValue<char>(
        std::string("ak[" + std::to_string(i) + "].v").c_str(), &val[0],
        size1 + 1);
    (&root)->getAuthKeys()[std::string(&key[0])] = std::string(&val[0]);
  }
}

void DB::fetchAutoModeConf(Root& root) {
  for (long d = 0; d < 7; d++) {
    std::list<TimeSpan> tss;
    long size;
    this->pDbC->fetchValue<long>(
        std::string("$ac[" + std::to_string(d) + "]").c_str(), &size, 1);
    for (long i = 0; i < size; i++) {
      long fh, fm, th, tm;
      this->pDbC->fetchValue<long>(
          std::string("ac[" + std::to_string(d) + "][" + std::to_string(i) +
                      "].fh")
              .c_str(),
          &fh, 1);
      this->pDbC->fetchValue<long>(
          std::string("ac[" + std::to_string(d) + "][" + std::to_string(i) +
                      "].fm")
              .c_str(),
          &fm, 1);
      this->pDbC->fetchValue<long>(
          std::string("ac[" + std::to_string(d) + "][" + std::to_string(i) +
                      "].th")
              .c_str(),
          &th, 1);
      this->pDbC->fetchValue<long>(
          std::string("ac[" + std::to_string(d) + "][" + std::to_string(i) +
                      "].tm")
              .c_str(),
          &tm, 1);
      (&tss)->push_back(TimeSpan(Time(fh, fm), Time(th, tm)));
    }
    (&root)->getAutoModeConf()[static_cast<WeekDay>(d)] = tss;
  }
}

void DB::fetchIntrusions(Root& root) {
  long size;
  this->pDbC->fetchValue<long>("$i", &size, 1);
  for (long i = 0; i < size; i++) {
    long id, date;
    bool notified;
    this->pDbC->fetchValue<long>(
        std::string("i[" + std::to_string(i) + "].i").c_str(), &id, 1);
    this->pDbC->fetchValue<long>(
        std::string("i[" + std::to_string(i) + "].d").c_str(), &date, 1);
    this->pDbC->fetchValue<bool>(
        std::string("i[" + std::to_string(i) + "].n").c_str(), &notified, 1);
    (&root)->getIntrusions().push_back(Intrusion(id, date, notified));
  }
}

void DB::storeAuthKeys(const Root& root) {
  long size = (&root)->getAuthKeys().size();
  this->pDbC->storeValue<long>("$ak", &size, 1);
  long i = 0;
  for (std::map<std::string, std::string>::iterator it =
           (&root)->getAuthKeys().begin();
       it != (&root)->getAuthKeys().end(); ++it) {
    long size1 = (&it->first)->size();
    this->pDbC->storeValue<long>(
        std::string("ak[" + std::to_string(i) + "].$k").c_str(), &size1, 1);
    this->pDbC->storeValue<char>(
        std::string("ak[" + std::to_string(i) + "].k").c_str(),
        (&it->first)->c_str(), (&it->first)->size() + 1);
    size1 = (&it->second)->size();
    this->pDbC->storeValue<long>(
        std::string("ak[" + std::to_string(i) + "].$v").c_str(), &size1, 1);
    this->pDbC->storeValue<char>(
        std::string("ak[" + std::to_string(i) + "].v").c_str(),
        (&it->second)->c_str(), (&it->second)->size() + 1);
    i++;
  }
}

void DB::storeAutoModeConf(const Root& root) {
  for (long d = 0; d < 7; d++) {
    long size = 0;
    std::map<WeekDay, std::list<TimeSpan>>::iterator it =
        (&root)->getAutoModeConf().find(static_cast<WeekDay>(d));
    if (it != (&root)->getAutoModeConf().end()) {
      size = (&root)->getAutoModeConf()[static_cast<WeekDay>(d)].size();
    }
    this->pDbC->storeValue<long>(
        std::string("$ac[" + std::to_string(d) + "]").c_str(), &size, 1);
    long i = 0;
    for (std::list<TimeSpan>::iterator it =
             (&root)->getAutoModeConf()[static_cast<WeekDay>(d)].begin();
         it != (&root)->getAutoModeConf()[static_cast<WeekDay>(d)].end();
         ++it) {
      long fh = it->getFrom().getHour(), fm = it->getFrom().getMinute(),
           th = it->getTo().getHour(), tm = it->getTo().getMinute();
      this->pDbC->storeValue<long>(
          std::string("ac[" + std::to_string(d) + "][" + std::to_string(i) +
                      "].fh")
              .c_str(),
          &fh, 1);
      this->pDbC->storeValue<long>(
          std::string("ac[" + std::to_string(d) + "][" + std::to_string(i) +
                      "].fm")
              .c_str(),
          &fm, 1);
      this->pDbC->storeValue<long>(
          std::string("ac[" + std::to_string(d) + "][" + std::to_string(i) +
                      "].th")
              .c_str(),
          &th, 1);
      this->pDbC->storeValue<long>(
          std::string("ac[" + std::to_string(d) + "][" + std::to_string(i) +
                      "].tm")
              .c_str(),
          &tm, 1);
      i++;
    }
  }
}

void DB::storeIntrusions(const Root& root) {
  long size = (&root)->getIntrusions().size();
  this->pDbC->storeValue<long>(std::string("$i").c_str(), &size, 1);
  long i = 0;
  for (std::list<Intrusion>::iterator it = (&root)->getIntrusions().begin();
       it != (&root)->getIntrusions().end(); ++it) {
    long id = it->getId(), date = it->getDate();
    bool notified = it->isNotified();
    this->pDbC->storeValue<long>(
        std::string("i[" + std::to_string(i) + "].i").c_str(), &id, 1);
    this->pDbC->storeValue<long>(
        std::string("i[" + std::to_string(i) + "].d").c_str(), &date, 1);
    this->pDbC->storeValue<bool>(
        std::string("i[" + std::to_string(i) + "].n").c_str(), &notified, 1);
    i++;
  }
}

Root DB::fetch() {
  Root root;
  bool autoMode, active;
  this->pDbC->fetchValue<bool>("am", &autoMode, 1);
  this->pDbC->fetchValue<bool>("a", &active, 1);
  (&root)->setAutoMode(autoMode);
  (&root)->setActive(active);
  this->fetchAuthKeys(root);
  this->fetchAutoModeConf(root);
  this->fetchIntrusions(root);
  return root;
}

void DB::store(const Root& root) {
  this->pDbC->deleteAll();
  bool autoMode = (&root)->isAutoMode(), active = (&root)->isActive();
  this->pDbC->storeValue<bool>("am", &autoMode, 1);
  this->pDbC->storeValue<bool>("a", &active, 1);
  this->storeAuthKeys(root);
  this->storeAutoModeConf(root);
  this->storeIntrusions(root);
}
