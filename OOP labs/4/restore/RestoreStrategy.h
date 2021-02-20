#pragma once

#include "../Backup.h"

class RestoreStrategy {
public:
  virtual void restore(Backup *backup) = 0;
  
protected:
  static FileRestoreInfo *getFileRestoreInfo(const std::string &path);
};

