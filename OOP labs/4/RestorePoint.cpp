#include "RestorePoint.h"

#include <ctime>

long long RestorePoint::getSize() {
  long long size = 0;
  for (auto info : *filesInfo) {
    size += info->size;
  }
  return size;
}

RestorePoint::RestorePoint(bool isIncremental, std::vector<FileRestoreInfo*> *filesInfo) {
  this->_isIncremental = isIncremental;
  this->filesInfo = filesInfo;
  this->creationTime = std::time(nullptr);
}

bool RestorePoint::isIncremental() {
  return _isIncremental;
}

std::vector<FileRestoreInfo*> *RestorePoint::getFilesInfo() {
  return filesInfo;
}

time_t RestorePoint::getCreationTime() {
  return creationTime;
}

