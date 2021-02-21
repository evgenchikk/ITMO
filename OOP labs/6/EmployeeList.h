#pragma once

#include "Employee.h"


class EmployeeList {
    Employee *leader = nullptr;

    static Employee *getEmployee(size_t ID, Employee *cur);

    static Employee *getEmployee(std::string name, Employee *cur);

    void print(Employee *cur, int space);

public:
    bool addEmployee(size_t ID, std::string name, int managerID);

    bool setManager(size_t employeeID, int managerID);

    Employee *getEmployee(size_t ID);

    Employee *getEmployee(std::string name);

    void print();
};
