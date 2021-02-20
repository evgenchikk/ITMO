#pragma once

#include "CleanStrategy.h"

class SizeCleanStrategy : public CleanStrategy {
public:
  SizeCleanStrategy(long long size);
  
  int cleanCount(Backup *backup) override;
  
private:
  long long size;
};
