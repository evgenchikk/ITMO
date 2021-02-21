#pragma once

#include "Task.h"
#include "SprintReport.h"


class Employee {
    size_t ID;
    std::string name;
    Employee *manager;
    std::vector<Employee *> subordinates;

    Report *dailyReport;
    SprintReport *sprintReport;

    void addSubordinate(Employee *subordinate);

    void removeSubordinate(Employee *subordinate);

    static std::vector<size_t> getAllSubordinatesID(Employee *cur);

public:
    Employee(size_t _ID, std::string _name, Employee *_manager = nullptr);

    void setManager(Employee *newManager);

    void startNewDailyReport();

    void startNewSprintReport();

    size_t getID();

    const std::string &getName();

    Employee *getManager();

    const std::vector<Employee *> &getSubordinates();

    Report *getDailyReport();

    SprintReport *getSprintReport();

    std::vector<size_t> getAllSubordinatesID();
};
