#include "TaskMenuView.h"
#include <iostream>

std::string TaskMenuView::getTaskCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

void TaskMenuView::showTaskMenu() {
    system("cls");
    std::cout << "  Task Menu\n";
    std::cout << "1 - Add new task\n";
    std::cout << "2 - Change task\n";
    std::cout << "3 - Show task by Id\n";
    std::cout << "4 - Show task with filter\n";
    std::cout << "e - Exit\n";
    std::cout << std::endl;
}
