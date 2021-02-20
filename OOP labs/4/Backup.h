#pragma once

#include "RestorePoint.h"
#include <ctime>
#include <vector>

class Backup {
public:
  Backup();
  
  int getId() const;
  
  time_t getCreationTime();
  
  long getSize();
  
  std::vector<RestorePoint *> *getPoints();
  
  std::vector<std::string> *getFiles();
  
  void addFile(const std::string &file);
  
  void removeFile(const std::string &file);
  
  void addPoint(RestorePoint *point);
  
  void removeFirstPoints(int count);
  
private:
  std::vector<RestorePoint *> *points;
  std::vector<std::string> *files;
  static int _id;
  int id;
  time_t creationTime;
};

