#include "EmployeeList.h"
#include <iostream>


Employee *EmployeeList::getEmployee(size_t ID, Employee *cur) {
    if (cur->getID() == ID)
        return cur;
    for (Employee *t : cur->getSubordinates()) {
        Employee *ans = getEmployee(ID, t);
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


void EmployeeList::print(Employee *cur, int space) {
    for (int i = 0; i < space; ++i)
        std::cout << " ";
    std::cout << cur->getID() << " " << cur->getName() << std::endl;
    for (Employee *t : cur->getSubordinates()) {
        print(t, space + 2);
    }
}


bool EmployeeList::addEmployee(size_t ID, std::string name, int managerID) {
    if (getEmployee(ID) != nullptr)
        return false;
    Employee *manager = nullptr;
    if (managerID >= 0) {
        manager = getEmployee(managerID);
        if (manager == nullptr)
            return false;
    }
    Employee *employee = new Employee(ID, name, manager);
    if (manager == nullptr) {
        if (leader != nullptr) {
            leader->setManager(employee);
        }
        leader = employee;
    }
    return true;
}


bool EmployeeList::setManager(size_t employeeID, int managerID) {
    Employee *employee = getEmployee(employeeID);
    if (employee == nullptr)
        return false;

    Employee *newManager = nullptr;
    if (managerID >= 0) {
        newManager = getEmployee(managerID);
        if (newManager == nullptr)
            return false;
    }

    if (newManager == employee->getManager() || newManager == employee)
        return false;

    employee->setManager(newManager);
    if (newManager == nullptr) {
        if (leader != nullptr) {
            leader->setManager(employee);
        }
        leader = employee;
    } else if (employee == leader) {
        leader = newManager;
    }
    return true;
}


Employee *EmployeeList::getEmployee(size_t ID) {
    if (leader == nullptr)
        return nullptr;
    return getEmployee(ID, leader);
}


Employee *EmployeeList::getEmployee(std::string name) {
    return getEmployee(name, leader);
}


void EmployeeList::print() {
    std::cout << "Team Hierarchy:\n";
    print(leader, 0);
}
