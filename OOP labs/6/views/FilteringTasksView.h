#pragma once

#include <string>
#include "../Task.h"

class FilteringTasksView {
    enum class PrintType {
        Id,
        CreationDate,
        LastChangeDate
    };

    void print(std::vector<Task *> *list, PrintType printType);

public:
    std::string getMenuCommand();

    int getEmployeeId();

    void showPrintingTasks();

    void showMenu();

    void showEmployeeIdError();

    void showIncorrectOption();

    void showTaskListById(std::vector<Task *> *list);

    void showTaskListByCreationTime(std::vector<Task *> *list);

    void showTaskListByChangeTime(std::vector<Task *> *list);

    void showTaskList(std::vector<Task *> *list);
};
