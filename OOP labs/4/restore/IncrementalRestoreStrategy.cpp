#include "IncrementalRestoreStrategy.h"

void IncrementalRestoreStrategy::restore(Backup *backup) {
  auto previousPoint = backup->getPoints()->back();
  auto files = backup->getFiles();
  auto *filesInfo = new std::vector<FileRestoreInfo *>();
  
  for (const auto &file : *files) {
    auto info = getFileRestoreInfo(file);
    
    auto previousSize = findInfo(*previousPoint, info->path).size;
    // calculate real diff?))
    info->size = previousSize - info->size / 2;
    
    filesInfo->push_back(info);
  }
  
  auto *point = new RestorePoint(false, filesInfo);
  backup->addPoint(point);
}

FileRestoreInfo IncrementalRestoreStrategy::findInfo(RestorePoint point, const std::string &path) {
  for (auto info : *point.getFilesInfo()) {
    if (info->path == path) {
      return *info;
    }
  }
  
  throw std::invalid_argument("No such file");
}

