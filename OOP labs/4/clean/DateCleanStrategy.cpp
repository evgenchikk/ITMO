#include "DateCleanStrategy.h"

int DateCleanStrategy::cleanCount(Backup *backup) {
  int count = 0;
  for (auto point : *backup->getPoints()) {
    if (point->getCreationTime() < time) {
      count++;
    } else {
      break;
    }
  }
  
  return count;
}

DateCleanStrategy::DateCleanStrategy(time_t time) {
  this->time = time;
}

