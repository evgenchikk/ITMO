#pragma once

#include "../EmployeeList.h"
#include "string"

class EmployeesView {
    void print(Employee *cur, int space);

public:
    std::string getEmployeeMenuCommand();

    void showEmployeesMenu();

    void showEmployees(EmployeeList *employeeList);
};
