#pragma once

#include "CleanStrategy.h"

class CountCleanStrategy : public CleanStrategy {
public:
  CountCleanStrategy(int count);
  
  int cleanCount(Backup *backup) override;
  
private:
  int count;
};
