#include "TaskList.h"
#include <iostream>
#include <algorithm>
#include "General.h"


bool TaskList::IDComparator(Task *left, Task *right) {
    return left->getID() < right->getID();
}


bool TaskList::creationTimeComparator(Task *left, Task *right) {
    return left->getCreationTime() < right->getCreationTime();
}


bool TaskList::lastChangeTimeComparator(Task *left, Task *right) {
    return left->getLastChangeTime() < right->getLastChangeTime();
}


void TaskList::print(std::vector<Task *> list, PrintType printType) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (printType == PrintType::CreationDate)
            std::cout << "Creation Date: " << getDateString(list[i]->getCreationTime());
        else if (printType == PrintType::LastChangeDate)
            std::cout << "Last Change Date: " << getDateString(list[i]->getLastChangeTime());
        std::cout << "ID: " << list[i]->getID() << std::endl;
        std::cout << "Name: " << list[i]->getName() << std::endl;
        if (list[i]->getEmployeeID() < 0)
            std::cout << "Employee: None" << std::endl;
        else
            std::cout << "Employee: " << list[i]->getEmployeeID() << std::endl;
        std::cout << "Status: " << list[i]->getStatus() << std::endl;
        std::cout << std::endl;
        if (i % PRINT_SIZE == PRINT_SIZE - 1) {
            std::cout << "Show more results? (y/n)" << std::endl;
            std::string ans;
            getline(std::cin, ans);
            if (ans != "y")
                return;
        }
    }
}


bool TaskList::addTask(size_t ID, std::string name, std::string description, size_t employeeID, size_t creatorID) {
    if (getTask(ID) != nullptr)
        return false;
    list.push_back(new Task(ID, name, description, employeeID, creatorID));
    return true;
}


Task *TaskList::getTask(size_t ID) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (ID == list[i]->getID())
            return list[i];
    }
    return nullptr;
}


void TaskList::printByID() {
    std::sort(list.begin(), list.end(), IDComparator);
    print(list, PrintType::ID);
}


void TaskList::printByCreationTime() {
    std::sort(list.begin(), list.end(), creationTimeComparator);
    print(list, PrintType::CreationDate);
}


void TaskList::printByLastChangeTime() {
    std::sort(list.begin(), list.end(), lastChangeTimeComparator);
    print(list, PrintType::LastChangeDate);
}


void TaskList::printAssigned(size_t employeeID) {
    std::vector<Task *> filteredList;
    for (size_t i = 0; i < list.size(); ++i) {
        if (list[i]->getEmployeeID() == employeeID)
            filteredList.push_back(list[i]);
    }
    sort(filteredList.begin(), filteredList.end(), IDComparator);
    print(filteredList, PrintType::ID);
}


void TaskList::printEdited(size_t employeeID) {
    std::vector<Task *> filteredList;
    for (size_t i = 0; i < list.size(); ++i)
        for (auto t : list[i]->getEditorsID())
            if (t == employeeID)
                filteredList.push_back(list[i]);
    sort(filteredList.begin(), filteredList.end(), IDComparator);
    print(filteredList, PrintType::ID);
}


void TaskList::printSubordinated(std::vector<size_t> employeesID) {
    std::vector<Task *> filteredList;
    for (size_t i = 0; i < list.size(); ++i)
        for (size_t j = 0; j < employeesID.size(); ++j)
            if (list[i]->getEmployeeID() == employeesID[j]) {
                filteredList.push_back(list[i]);
                break;
            }
    sort(filteredList.begin(), filteredList.end(), IDComparator);
    print(filteredList, PrintType::ID);
}
