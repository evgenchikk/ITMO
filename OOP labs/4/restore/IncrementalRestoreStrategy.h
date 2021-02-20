#pragma once

#include "RestoreStrategy.h"
#include "../RestorePoint.h"
#include "../Backup.h"

class IncrementalRestoreStrategy : public RestoreStrategy {
public:
  void restore(Backup *backup) override;
  
private:
  static FileRestoreInfo findInfo(RestorePoint point, const std::string &path);
};
