#include "SizeCleanStrategy.h"

int SizeCleanStrategy::cleanCount(Backup *backup) {
  auto currentSize = backup->getSize();
  int count = 0;
  while (currentSize > size && count < backup->getPoints()->size()) {
    currentSize -= (*backup->getPoints())[count]->getSize();
    count++;
  }
  
  return count;
}

SizeCleanStrategy::SizeCleanStrategy(long long int size) {
  this->size = size;
}

