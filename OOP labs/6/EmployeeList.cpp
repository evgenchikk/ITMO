#include "EmployeeList.h"

Employee *EmployeeList::getEmployee(size_t Id, Employee *cur) {
    if (cur->getId() == Id)
        return cur;
    for (Employee *t : cur->getSubordinates()) {
        Employee *ans = getEmployee(Id, t);
        if (ans != nullptr)
            return ans;
    }
    return nullptr;
}

Employee *EmployeeList::getEmployee(std::string name, Employee *cur) {
    if (cur->getName() == name)
        return cur;
    for (Employee *t : cur->getSubordinates()) {
        Employee *ans = getEmployee(name, t);
        if (ans != nullptr)
            return ans;
    }
    return nullptr;
}

void EmployeeList::setTeamlead(Employee *newTeamlead) {
    teamlead.setEmployee(newTeamlead);
    if (teamlead.getSprintReport() == nullptr)
        teamlead.startNewSprintReport();
}

bool EmployeeList::addEmployee(size_t Id, std::string name, int managerId) {
    if (getEmployee(Id) != nullptr)
        return false;
    Employee *manager = nullptr;
    if (managerId >= 0) {
        manager = getEmployee(managerId);
        if (manager == nullptr)
            return false;
    }
    auto *employee = new Employee(Id, name, manager);
    if (manager == nullptr) {
        if (teamlead.getEmployee() != nullptr) {
            teamlead.getEmployee()->setManager(employee);
        }
        setTeamlead(employee);
    }
    return true;
}

bool EmployeeList::setManager(size_t employeeId, int managerId) {
    Employee *employee = getEmployee(employeeId);
    if (employee == nullptr)
        return false;

    Employee *newManager = nullptr;
    if (managerId >= 0) {
        newManager = getEmployee(managerId);
        if (newManager == nullptr)
            return false;
    }

    if (newManager == employee->getManager() || newManager == employee)
        return false;

    employee->setManager(newManager);
    if (newManager == nullptr) {
        if (teamlead.getEmployee() != nullptr) {
            teamlead.getEmployee()->setManager(employee);
        }
        setTeamlead(employee);
    } else if (employee == teamlead.getEmployee()) {
        setTeamlead(newManager);
    }
    return true;
}

Employee *EmployeeList::getEmployee(size_t Id) {
    if (teamlead.getEmployee() == nullptr)
        return nullptr;
    return getEmployee(Id, teamlead.getEmployee());
}

Employee *EmployeeList::getEmployee(std::string name) {
    if (teamlead.getEmployee() == nullptr)
        return nullptr;
    return getEmployee(name, teamlead.getEmployee());
}

TeamleadWrapper &EmployeeList::getTeamlead() {
    return teamlead;
}
