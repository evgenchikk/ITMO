#include <sys/stat.h>
#include "RestoreStrategy.h"

FileRestoreInfo *RestoreStrategy::getFileRestoreInfo(const std::string &path) {
  struct stat stat_buf;
  int rc = stat(path.c_str(), &stat_buf);
  long long fileSize = rc == 0 ? stat_buf.st_size : -1;
  time_t currentTime = std::time(nullptr);
  return new FileRestoreInfo{path, fileSize, currentTime};
};

