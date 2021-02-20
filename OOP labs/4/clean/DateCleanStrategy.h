#pragma once

#include "CleanStrategy.h"

class DateCleanStrategy : public CleanStrategy {
public:
  DateCleanStrategy(time_t time);
  
  int cleanCount(Backup *backup) override;
  
private:
  time_t time;
};
