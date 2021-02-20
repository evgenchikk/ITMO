cmake_minimum_required(VERSION 3.17)
project(clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(clion main.cpp restore/RestoreStrategy.cpp RestorePoint.cpp restore/FullRestoreStrategy.cpp Backup.cpp BackupManager.cpp restore/IncrementalRestoreStrategy.cpp clean/DateCleanStrategy.cpp clean/DateCleanStrategy.h clean/SizeCleanStrategy.cpp clean/CountCleanStrategy.cpp clean/AllHybridCleanStrategy.cpp clean/AllHybridCleanStrategy.h clean/AnyHybridCleanStrategy.cpp clean/AnyHybridCleanStrategy.h)