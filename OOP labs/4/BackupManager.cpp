#include "BackupManager.h"

void BackupManager::createRestorePoint(Backup *backup, RestoreStrategy *strategy) {
  strategy->restore(backup);
}

void BackupManager::clean(Backup *backup, CleanStrategy *strategy) {
  backup->removeFirstPoints(strategy->cleanCount(backup));
}

