#include "AllHybridCleanStrategy.h"

AllHybridCleanStrategy::AllHybridCleanStrategy(std::vector<CleanStrategy *> *strategies) {
  this->strategies = strategies;
}

int AllHybridCleanStrategy::cleanCount(Backup *backup) {
  if (strategies->empty()) return 0;
  
  int minCount = INT_MAX;
  for (auto strategy : *strategies) {
    int count = strategy->cleanCount(backup);
    if (count < minCount) {
      minCount = count;
    }
  }
  
  return minCount;
}

