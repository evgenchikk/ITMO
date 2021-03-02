#pragma once

#include "TeamleadWrapper.h"

class EmployeeList {
    TeamleadWrapper teamlead;

    static Employee *getEmployee(size_t Id, Employee *cur);

    static Employee *getEmployee(std::string name, Employee *cur);

    void setTeamlead(Employee *newTeamlead);

public:
    bool addEmployee(size_t Id, std::string name, int managerId);

    bool setManager(size_t employeeId, int managerId);

    Employee *getEmployee(size_t Id);

    Employee *getEmployee(std::string name);

    TeamleadWrapper &getTeamlead();
};
