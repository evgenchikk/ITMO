#include "Employee.h"


void Employee::addSubordinate(Employee *subordinate) {
    subordinates.push_back(subordinate);
}


void Employee::removeSubordinate(Employee *subordinate) {
    for (size_t i = 0; i < subordinates.size(); ++i)
        if (subordinates[i] == subordinate) {
            subordinates.erase(subordinates.begin() + i);
            return;
        }
}


std::vector<size_t> Employee::getAllSubordinatesID(Employee *cur) {
    std::vector<size_t> ans;
    for (auto t : cur->subordinates) {
        std::vector<size_t> tans = getAllSubordinatesID(t);
        for (size_t i = 0; i < tans.size(); ++i)
            ans.push_back(tans[i]);
    }
    ans.push_back(cur->getID());
    return ans;
}


Employee::Employee(size_t _ID, std::string _name, Employee *_manager) :
        ID(_ID), name(_name), manager(_manager), dailyReport(new Report(ID)), sprintReport(new SprintReport(ID)) {
    if (manager != nullptr)
        manager->addSubordinate(this);
}


void Employee::setManager(Employee *newManager) {
    if (manager != nullptr)
        manager->removeSubordinate(this);

    std::vector<size_t> subordinatesList = getAllSubordinatesID();
    for (auto t : subordinatesList) {
        if (t == newManager->getID()) {
            newManager->setManager(manager);
            break;
        }
    }

    manager = newManager;
    if (newManager != nullptr)
        newManager->addSubordinate(this);
}


void Employee::startNewDailyReport() {
    dailyReport = new Report(ID);
}


void Employee::startNewSprintReport() {
    sprintReport = new SprintReport(ID);
}


size_t Employee::getID() {
    return ID;
}


const std::string &Employee::getName() {
    return name;
}


Employee *Employee::getManager() {
    return manager;
}


const std::vector<Employee *> &Employee::getSubordinates() {
    return subordinates;
}


Report *Employee::getDailyReport() {
    return dailyReport;
}


SprintReport *Employee::getSprintReport() {
    return sprintReport;
}


std::vector<size_t> Employee::getAllSubordinatesID() {
    if (subordinates.size() == 0)
        return std::vector<size_t>();
    std::vector<size_t> ans = getAllSubordinatesID(this);
    ans.pop_back();
    return ans;
}
