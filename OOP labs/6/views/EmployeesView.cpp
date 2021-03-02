#include "EmployeesView.h"

#include <iostream>

std::string EmployeesView::getEmployeeMenuCommand() {
    std::string input;
    system("cls");
    getline(std::cin, input);
    return input;
}

void EmployeesView::showEmployeesMenu() {
    std::cout << "  Employee Menu\n";
    std::cout << "1 - Add new employee\n";
    std::cout << "2 - Change employee's manager\n";
    std::cout << "3 - Show all employees\n";
    std::cout << "e - Exit\n";
    std::cout << std::endl;
}

void EmployeesView::showEmployees(EmployeeList *employeeList) {
    system("cls");
    std::cout << "Team Hierarchy:\n";
    print(employeeList->getTeamlead().getEmployee(), 0);
}

void EmployeesView::print(Employee *cur, int space) {
    for (int i = 0; i < space; ++i)
        std::cout << " ";
    std::cout << cur->getId() << " " << cur->getName() << std::endl;
    for (Employee *t : cur->getSubordinates()) {
        print(t, space + 2);
    }
}
