#include "AnyHybridCleanStrategy.h"

AnyHybridCleanStrategy::AnyHybridCleanStrategy(std::vector<CleanStrategy *> *strategies) {
  this->strategies = strategies;
}

int AnyHybridCleanStrategy::cleanCount(Backup *backup) {
  if (strategies->empty()) return 0;
  
  int maxCount = 0;
  for (auto strategy : *strategies) {
    int count = strategy->cleanCount(backup);
    if (count > maxCount) {
      maxCount = count;
    }
  }
  
  return maxCount;
}

