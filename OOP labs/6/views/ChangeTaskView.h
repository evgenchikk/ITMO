#pragma once

#include "string"

class ChangeTaskView {
public:
    int getTaskId();

    std::string getTaskChangingCommand();

    int getEmployeeId();

    int getStatusMenuCommand();

    std::string getComment();

    void showChangingTask();

    void showGuestChangingTaskError();

    void showWrongIdError();

    void showTaskChangingMenu();

    void showIncorrectEmployeeId();

    void showChangedAssignedEmployee();

    void showStatusMenu();

    void showIncorrectStatus();

    void showStatusChanged();

    void showResolvedTaskAdded();

    void showCommentAdded();

    void showWrongOption();
};
