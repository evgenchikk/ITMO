#pragma once

#include "CleanStrategy.h"

class AnyHybridCleanStrategy : public CleanStrategy {
public:
  AnyHybridCleanStrategy(std::vector<CleanStrategy *> *strategies);
  
  int cleanCount(Backup *backup) override;
  
private:
  std::vector<CleanStrategy *> *strategies;
};

