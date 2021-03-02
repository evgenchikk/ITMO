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

std::vector<size_t> Employee::getAllSubordinatesId(Employee *cur) {
    std::vector <size_t> ans;
    for (auto t : cur->subordinates) {
        std::vector <size_t> tans = getAllSubordinatesId(t);
        for (size_t i = 0; i < tans.size(); ++i)
            ans.push_back(tans[i]);
    }
    ans.push_back(cur->getId());
    return ans;
}

Employee::Employee(size_t _Id, std::string _name, Employee *_manager) :
        Id(_Id), name(_name), manager(_manager), dailyReport(new Report(Id)), sprintDraft(new SprintDraft(Id)) {
    if (manager != nullptr)
        manager->addSubordinate(this);
}

void Employee::setManager(Employee *newManager) {
    if (manager != nullptr)
        manager->removeSubordinate(this);

    std::vector <size_t> subordinatesList = getAllSubordinatesId();
    for (auto t : subordinatesList) {
        if (t == newManager->getId()) {
            newManager->setManager(manager);
            break;
        }
    }

    manager = newManager;
    if (newManager != nullptr)
        newManager->addSubordinate(this);
}

void Employee::startNewDailyReport() {
    dailyReport = new Report(Id);
}

void Employee::startNewSprintDraft() {
    sprintDraft = new SprintDraft(Id);
}

size_t Employee::getId() {
    return Id;
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

SprintDraft *Employee::getSprintDraft() {
    return sprintDraft;
}

std::vector<size_t> Employee::getAllSubordinatesId() {
    if (subordinates.size() == 0)
        return std::vector<size_t>();
    std::vector<size_t> ans = getAllSubordinatesId(this);
    ans.pop_back();
    return ans;
}
