#pragma once

#include "Employee.h"
#include "SprintReport.h"

class TeamleadWrapper {
    Employee *teamlead = nullptr;
    SprintReport *sprintReport = nullptr;

public:

    Employee *getEmployee();

    void setEmployee(Employee *newTeamlead);

    void startNewSprintReport();

    SprintReport *getSprintReport();
};
