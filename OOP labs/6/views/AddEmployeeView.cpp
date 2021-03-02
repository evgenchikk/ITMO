#include "AddEmployeeView.h"
#include <iostream>

int AddEmployeeView::getNewEmployeeId() {
    std::string input;
    std::cout << "Id: ";
    getline(std::cin, input);
    return stoi(input);
}

std::string AddEmployeeView::getNewEmployeeName() {
    std::string name;
    std::cout << "Name: ";
    getline(std::cin, name);
    return name;
}

int AddEmployeeView::getManagersId() {
    std::string input;
    std::cout << "Manager's Id (-1 to make new employee the teamlead): ";
    getline(std::cin, input);
    return stoi(input);
}

void AddEmployeeView::showEmployeeAdded() {
    std::cout << "Added new employee!\n";
}

void AddEmployeeView::showError() {
    std::cout << "Error!\n";
}

void AddEmployeeView::showAddingEmployee() {
    system("cls");
    std::cout << "  Adding new employee\n";
}
