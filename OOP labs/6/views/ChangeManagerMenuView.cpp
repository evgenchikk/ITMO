#include "ChangeManagerMenuView.h"
#include <iostream>

int ChangeManagerMenuView::getNewManagersId() {
    std::string input;
    std::cout << "New manager's Id (-1 to make employee the teamlead): ";
    getline(std::cin, input);
    return stoi(input);
}

void ChangeManagerMenuView::showChangingEmployee() {
    system("cls");
    std::cout << "  Changing employee's manager\n";
}

int ChangeManagerMenuView::getId() {
    std::string input;
    std::cout << "Id: ";
    getline(std::cin, input);
    return stoi(input);
}

void ChangeManagerMenuView::showError() {
    std::cout << "Error!\n";
}

void ChangeManagerMenuView::showManagerChanged() {
    std::cout << "Changed manager!\n";
}
