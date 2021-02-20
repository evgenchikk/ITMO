#include "Backup.h"

int Backup::_id = 0;

Backup::Backup() {
  this->id = _id++;
  this->creationTime = std::time(0);
  this->points = new std::vector<RestorePoint *>();
  this->files = new std::vector<std::string>();
}

int Backup::getId() const {
  return id;
}

time_t Backup::getCreationTime() {
  return creationTime;
}

long Backup::getSize() {
  long long size = 0;
  for (auto point : *points) {
    size += point->getSize();
  }
  return size;
}

std::vector<RestorePoint *> *Backup::getPoints() {
  return points;
}

std::vector<std::string> *Backup::getFiles() {
  return files;
}

void Backup::addFile(const std::string &file) {
  files->push_back(file);
}

void Backup::removeFile(const std::string &file) {
  files->erase(std::remove(files->begin(), files->end(), file), files->end());
}

void Backup::addPoint(RestorePoint *point) {
  points->push_back(point);
}

void Backup::removeFirstPoints(int count) {
  points->erase(points->begin(), points->begin() + count);
}

