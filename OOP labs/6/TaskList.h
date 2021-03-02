#pragma once

#include "Task.h"

class TaskList {
    std::vector<Task *> list;

    static bool IdComparator(Task *left, Task *right);

    static bool creationTimeComparator(Task *left, Task *right);

    static bool lastChangeTimeComparator(Task *left, Task *right);

public:
    bool addTask(size_t Id, std::string name, std::string description, size_t employeeId, size_t creatorId);

    Task *getTask(size_t Id);

    std::vector<Task *> *getSortedById();

    std::vector<Task *> *getSortedByCreationTime();

    std::vector<Task *> *getSortedByLastChangeTime();

    std::vector<Task *> *getAssigned(size_t employeeId);

    std::vector<Task *> *getEdited(size_t employeeId);

    std::vector<Task *> *getSubordinated(const std::vector<size_t> &employeesId);
};
