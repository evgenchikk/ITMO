#include "MainMenuView.h"
#include <iostream>

std::string MainMenuView::getMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

void MainMenuView::showMenu() {
    std::cout << std::endl;
    std::cout << "  Main Menu\n";
    std::cout << "1 - Employees\n";
    std::cout << "2 - Tasks\n";
    std::cout << "3 - Reports\n";
    std::cout << "4 - Change User\n";
    std::cout << "e - Exit\n";
    std::cout << std::endl;
}

void MainMenuView::showCurrentUser(int userId) {
    system("cls");
    std::cout << "Current User: ";
    if (userId == -1)
        std::cout << "Guest";
    else
        std::cout << userId;
}
