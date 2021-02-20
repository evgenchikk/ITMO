#pragma once

#include "FileRestoreInfo.h"
#include <vector>

class RestorePoint {
public:
  RestorePoint(bool isIncremental, std::vector<FileRestoreInfo *> *filesInfo);
  
  bool isIncremental();
  
  std::vector<FileRestoreInfo *> *getFilesInfo();
  
  long long getSize();
  
  time_t getCreationTime();
  
private:
  bool _isIncremental;
  std::vector<FileRestoreInfo *> *filesInfo;
  time_t creationTime;
};

