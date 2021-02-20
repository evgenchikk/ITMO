#pragma once

#include <string>

struct FileRestoreInfo {
  std::string path;
  long long size;
  time_t creationTime;
};

