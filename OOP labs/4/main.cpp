#include <iostream>
#include "BackupManager.h"
#include "restore/FullRestoreStrategy.h"
#include "restore/IncrementalRestoreStrategy.h"
#include "clean/CountCleanStrategy.h"
#include "clean/DateCleanStrategy.h"
#include "clean/AnyHybridCleanStrategy.h"
#include "clean/AllHybridCleanStrategy.h"

std::string testFile = "/Users/fansin/Documents/Vacancy.docx";

int main() {
  auto backup = Backup();
  backup.addFile(testFile);
  auto fullRestoreStrategy = FullRestoreStrategy();
  auto incrementalRestoreStrategy = IncrementalRestoreStrategy();
  
  BackupManager::createRestorePoint(&backup, &fullRestoreStrategy);
  std::cout << backup.getSize() << std::endl;
  
  BackupManager::createRestorePoint(&backup, &incrementalRestoreStrategy);
  std::cout << backup.getSize() << std::endl;
  
  BackupManager::clean(&backup, new CountCleanStrategy(2));
  std::cout << backup.getSize() << std::endl;
  
  BackupManager::clean(&backup, new DateCleanStrategy(std::time(nullptr)));
  std::cout << backup.getSize() << std::endl;
  
  auto strategies = new std::vector<CleanStrategy*>();
  strategies->push_back(new DateCleanStrategy(std::time(nullptr) + 100));
  strategies->push_back(new CountCleanStrategy(2));
  BackupManager::clean(&backup, new AllHybridCleanStrategy(strategies));
  std::cout << backup.getSize() << std::endl;
  
  strategies = new std::vector<CleanStrategy*>();
  strategies->push_back(new DateCleanStrategy(std::time(nullptr)));
  strategies->push_back(new CountCleanStrategy(1));
  BackupManager::clean(&backup, new AnyHybridCleanStrategy(strategies));
  std::cout << backup.getSize() << std::endl;
}

