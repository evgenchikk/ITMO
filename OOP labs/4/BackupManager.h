#pragma once

#include "Backup.h"
#include "restore/RestoreStrategy.h"
#include "clean/CleanStrategy.h"

class BackupManager {
public:
  static void createRestorePoint(Backup *backup, RestoreStrategy *strategy);
  
  static void clean(Backup *backup, CleanStrategy *strategy);
};
