#include "FilteringTasksView.h"
#include "../General.h"
#include <iostream>

std::string FilteringTasksView::getMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

int FilteringTasksView::getEmployeeId() {
    std::string input;
    std::cout << "Employee Id: ";
    getline(std::cin, input);
    return stoi(input);
}

void FilteringTasksView::showPrintingTasks() {
    system("cls");
    std::cout << "  Printing tasks\n";
}

void FilteringTasksView::showMenu() {
    std::cout << "1 - Order by Id\n";
    std::cout << "2 - Order by creation date\n";
    std::cout << "3 - Order by last change date\n";
    std::cout << "4 - All tasks, assigned to specific employee\n";
    std::cout << "5 - All tasks, ever edited by specific employee\n";
    std::cout << "6 - All tasks, that are assigned to subordinates of specific employee\n";
}

void FilteringTasksView::showEmployeeIdError() {
    std::cout << "Incorrect employee Id!\n";
}

void FilteringTasksView::showIncorrectOption() {
    std::cout << "Incorrect option!\n";
}

void FilteringTasksView::print(std::vector<Task *> *list, PrintType printType) {
    for (auto &i : *list) {
        if (printType == PrintType::CreationDate)
            std::cout << "Creation Date: " << getDateString(i->getCreationTime());
        else if (printType == PrintType::LastChangeDate)
            std::cout << "Last Change Date: " << getDateString(i->getLastChangeTime());
        std::cout << "Id: " << i->getId() << std::endl;
        std::cout << "Name: " << i->getName() << std::endl;
        if (i->getEmployeeId() < 0)
            std::cout << "Employee: None" << std::endl;
        else
            std::cout << "Employee: " << i->getEmployeeId() << std::endl;
        std::cout << "Status: " << i->getStatus() << std::endl;
        std::cout << std::endl;
    }
}

void FilteringTasksView::showTaskListById(std::vector<Task *> *list) {
    print(list, PrintType::Id);
}

void FilteringTasksView::showTaskListByCreationTime(std::vector<Task *> *list) {
    print(list, PrintType::CreationDate);
}

void FilteringTasksView::showTaskListByChangeTime(std::vector<Task *> *list) {
    print(list, PrintType::LastChangeDate);
}

void FilteringTasksView::showTaskList(std::vector<Task *> *list) {
    print(list, PrintType::Id);
}
