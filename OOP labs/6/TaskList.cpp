#include "TaskList.h"
#include <algorithm>

bool TaskList::IdComparator(Task *left, Task *right) {
    return left->getId() < right->getId();
}

bool TaskList::creationTimeComparator(Task *left, Task *right) {
    return left->getCreationTime() < right->getCreationTime();
}

bool TaskList::lastChangeTimeComparator(Task *left, Task *right) {
    return left->getLastChangeTime() < right->getLastChangeTime();
}

bool TaskList::addTask(size_t Id, std::string name, std::string description, size_t employeeId, size_t creatorId) {
    if (getTask(Id) != nullptr)
        return false;
    list.push_back(new Task(Id, name, description, employeeId, creatorId));
    return true;
}

Task *TaskList::getTask(size_t Id) {
    for (auto &i : list) {
        if (Id == i->getId())
            return i;
    }
    return nullptr;
}

std::vector<Task *> *TaskList::getSortedById() {
    auto *result = new std::vector<Task *>(list);
    std::sort(result->begin(), result->end(), IdComparator);
    return result;
}

std::vector<Task *> *TaskList::getSortedByCreationTime() {
    auto *result = new std::vector<Task *>(list);
    std::sort(result->begin(), result->end(), creationTimeComparator);
    return result;
}

std::vector<Task *> *TaskList::getSortedByLastChangeTime() {
    auto *result = new std::vector<Task *>(list);
    std::sort(result->begin(), result->end(), lastChangeTimeComparator);
    return result;
}

std::vector<Task *> *TaskList::getAssigned(size_t employeeId) {
    auto *filteredList = new std::vector<Task *>();
    for (auto &i : list) {
        if (i->getEmployeeId() == employeeId)
            filteredList->push_back(i);
    }
    sort(filteredList->begin(), filteredList->end(), IdComparator);
    return filteredList;
}

std::vector<Task *> *TaskList::getEdited(size_t employeeId) {
    auto *filteredList = new std::vector<Task *>();
    for (auto &i : list)
        for (auto t : i->getEditorsId())
            if (t == employeeId)
                filteredList->push_back(i);
    sort(filteredList->begin(), filteredList->end(), IdComparator);
    return filteredList;
}

std::vector<Task *> *TaskList::getSubordinated(const std::vector<size_t> &employeesId) {
    auto *filteredList = new std::vector<Task *>();
    for (auto &i : list) {
        for (unsigned long j : employeesId) {
            if (i->getEmployeeId() == j) {
                filteredList->push_back(i);
                break;
            }
        }
    }
    sort(filteredList->begin(), filteredList->end(), IdComparator);
    return filteredList;
}
