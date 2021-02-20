#include "FullRestoreStrategy.h"

void FullRestoreStrategy::restore(Backup *backup) {
  auto files = backup->getFiles();
  auto *filesInfo = new std::vector<FileRestoreInfo *>();
  
  for (const auto &file : *files) {
    filesInfo->push_back(getFileRestoreInfo(file));
  }
  
  auto *point = new RestorePoint(false, filesInfo);
  backup->addPoint(point);
}

