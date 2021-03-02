#pragma once

#include "Task.h"
#include "SprintDraft.h"

class Employee {
    size_t Id;
    std::string name;
    Employee *manager;
    std::vector<Employee *> subordinates;

    Report *dailyReport;
    SprintDraft *sprintDraft;

    void addSubordinate(Employee *subordinate);

    void removeSubordinate(Employee *subordinate);

    static std::vector<size_t> getAllSubordinatesId(Employee *cur);

public:
    Employee(size_t _Id, std::string _name, Employee *_manager = nullptr);

    void setManager(Employee *newManager);

    void startNewDailyReport();

    void startNewSprintDraft();

    size_t getId();

    const std::string &getName();

    Employee *getManager();

    const std::vector<Employee *> &getSubordinates();

    Report *getDailyReport();

    SprintDraft *getSprintDraft();

    std::vector<size_t> getAllSubordinatesId();
};
