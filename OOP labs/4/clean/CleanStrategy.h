#pragma once

#include "../Backup.h"

class CleanStrategy {
public:
  virtual int cleanCount(Backup *backup) = 0;
};
