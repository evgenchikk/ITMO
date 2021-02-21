#pragma once

#include "Task.h"


class TaskList {
    static const size_t PRINT_SIZE = 5;

    std::vector<Task *> list;

    static bool IDComparator(Task *left, Task *right);

    static bool creationTimeComparator(Task *left, Task *right);

    static bool lastChangeTimeComparator(Task *left, Task *right);

    enum class PrintType {
        ID,
        CreationDate,
        LastChangeDate
    };

    static void print(std::vector<Task *> list, PrintType printType);

public:
    bool addTask(size_t ID, std::string name, std::string description, size_t employeeID, size_t creatorID);

    Task *getTask(size_t ID);

    void printByID();

    void printByCreationTime();

    void printByLastChangeTime();

    void printAssigned(size_t employeeID);

    void printEdited(size_t employeeID);

    void printSubordinated(std::vector<size_t> employeesID);
};
