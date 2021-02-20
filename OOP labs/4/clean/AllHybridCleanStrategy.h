#pragma once

#include "CleanStrategy.h"

class AllHybridCleanStrategy : public CleanStrategy {
public:
  AllHybridCleanStrategy(std::vector<CleanStrategy *> *strategies);
  
  int cleanCount(Backup *backup) override;
  
private:
  std::vector<CleanStrategy *> *strategies;
};

