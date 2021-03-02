#include "AddTaskView.h"
#include <iostream>

int AddTaskView::getTaskId() {
    std::string input;
    std::cout << "Task Id: ";
    getline(std::cin, input);
    return stoi(input);
}

std::string AddTaskView::getTaskName() {
    std::string input;
    std::cout << "Name: ";
    getline(std::cin, input);
    return input;
}

std::string AddTaskView::getTaskDescription() {
    std::string input;
    std::cout << "Description: ";
    getline(std::cin, input);
    return input;
}

int AddTaskView::getAssigneeId() {
    std::string input;
    std::cout << "Employee's Id (-1 to don't assign): ";
    getline(std::cin, input);
    return stoi(input);
}

void AddTaskView::showAddingNewTask() {
    system("cls");
    std::cout << "  Adding new task\n";
}

void AddTaskView::showGuestAddingTaskError() {
    std::cout << "Guests can't add tasks!\n";
}

void AddTaskView::showTaskAdded() {
    std::cout << "Added new task!\n";
}

void AddTaskView::showError() {
    std::cout << "Error!\n";
}
