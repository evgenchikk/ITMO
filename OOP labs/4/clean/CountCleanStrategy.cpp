#include "CountCleanStrategy.h"

int CountCleanStrategy::cleanCount(Backup *backup) {
  return backup->getPoints()->size() - count;
}

CountCleanStrategy::CountCleanStrategy(int count) {
  this->count = count;
}

