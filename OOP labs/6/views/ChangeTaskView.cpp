#include "ChangeTaskView.h"
#include <iostream>

int ChangeTaskView::getTaskId() {
    std::string input;
    std::cout << "Task Id: ";
    getline(std::cin, input);
    return stoi(input);
}

std::string ChangeTaskView::getTaskChangingCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

int ChangeTaskView::getEmployeeId() {
    std::string input;
    std::cout << "Employee Id (-1 to unassign task): ";
    getline(std::cin, input);
    return stoi(input);
}

int ChangeTaskView::getStatusMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return stoi(input);
}

std::string ChangeTaskView::getComment() {
    std::string input;
    std::cout << "Comment: ";
    getline(std::cin, input);
    return input;
}

void ChangeTaskView::showChangingTask() {
    system("cls");
    std::cout << "  Changing task\n";
}

void ChangeTaskView::showGuestChangingTaskError() {
    std::cout << "Guests can't change tasks!\n";
}

void ChangeTaskView::showWrongIdError() {
    std::cout << "Wrong Id!\n";
}

void ChangeTaskView::showTaskChangingMenu() {
    std::cout << "1 - Change assigned employee\n";
    std::cout << "2 - Change status\n";
    std::cout << "3 - Add comment\n";
}

void ChangeTaskView::showIncorrectEmployeeId() {
    std::cout << "Incorrect employee Id!\n";
}

void ChangeTaskView::showChangedAssignedEmployee() {
    std::cout << "Changed assigned employee!\n";
}

void ChangeTaskView::showStatusMenu() {
    std::cout << "1 - Open\n";
    std::cout << "2 - Active\n";
    std::cout << "3 - Resolved\n";
}

void ChangeTaskView::showIncorrectStatus() {
    std::cout << "Incorrect status!\n";
}

void ChangeTaskView::showStatusChanged() {
    std::cout << "Changed status!\n";
}

void ChangeTaskView::showResolvedTaskAdded() {
    std::cout << "Added resolved task to report!\n";
}

void ChangeTaskView::showCommentAdded() {
    std::cout << "Added comment!\n";
}

void ChangeTaskView::showWrongOption() {
    std::cout << "Wrong option!\n";
}
