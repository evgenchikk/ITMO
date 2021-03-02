#pragma once

#include "../Task.h"
#include "string"

class TaskView {
public:
    int getTaskId();

    std::string getMenuCommand();

    void showPrintingTaskDetails();

    void showTask(Task *task);

    void showMenu();

    void showWrongId();

    void showComments(const std::vector<TimedPost *> &comments);

    void showHistory(const std::vector<TimedPost *> &history);
};
