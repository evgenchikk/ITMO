#pragma once

#include "string"

class AddEmployeeView {
public:
    int getNewEmployeeId();

    std::string getNewEmployeeName();

    int getManagersId();

    void showAddingEmployee();

    void showEmployeeAdded();

    void showError();
};

