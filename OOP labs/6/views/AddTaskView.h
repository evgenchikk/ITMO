#pragma once

#include "string"

class AddTaskView {
public:
    int getTaskId();

    std::string getTaskName();

    std::string getTaskDescription();

    int getAssigneeId();

    void showAddingNewTask();

    void showGuestAddingTaskError();

    void showError();

    void showTaskAdded();
};
