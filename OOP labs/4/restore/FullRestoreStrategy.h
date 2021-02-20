#pragma once

#include "RestoreStrategy.h"
#include "../RestorePoint.h"
#include "../Backup.h"

class FullRestoreStrategy : public RestoreStrategy {
public:
  void restore(Backup *backup) override;
};

