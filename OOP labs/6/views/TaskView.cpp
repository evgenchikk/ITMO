#include "TaskView.h"
#include <iostream>
#include "../General.h"

int TaskView::getTaskId() {
    std::string input;
    std::cout << "Task Id: ";
    getline(std::cin, input);
    return stoi(input);
}

std::string TaskView::getMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

void TaskView::showPrintingTaskDetails() {
    system("cls");
    std::cout << "  Printing Task Details\n";
}

void TaskView::showTask(Task *task) {
    std::cout << "Name: " << task->getName() << std::endl;
    std::cout << "Description: " << task->getDescription() << std::endl;
    std::cout << "Assigned Employee's Id: " << task->getEmployeeId() << std::endl;
    std::cout << "Status: " << task->getStatus() << std::endl;
}

void TaskView::showMenu() {
    std::cout << std::endl;
    std::cout << "1 - Show comments\n";
    std::cout << "2 - Show history\n";
}

void TaskView::showComments(const std::vector<TimedPost *> &comments) {
    for (auto &comment : comments) {
        std::cout << getDateString(comment->getTime()) << std::endl;
        std::cout << comment->getText() << std::endl;
        std::cout << "By: " << comment->getAuthorId() << std::endl;
        std::cout << std::endl;
    }
}

void TaskView::showHistory(const std::vector<TimedPost *> &history) {
    for (auto &i : history) {
        std::cout << getDateString(i->getTime()) << std::endl;
        std::cout << i->getText() << std::endl;
        std::cout << "By: " << i->getAuthorId() << std::endl;
        std::cout << std::endl;
    }
}

void TaskView::showWrongId() {
    std::cout << "Wrong Id!\n";
}
