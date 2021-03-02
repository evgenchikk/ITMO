#include "SubmittedReportsView.h"
#include <iostream>

std::string SubmittedReportsView::getMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

std::string SubmittedReportsView::getReportMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

std::string SubmittedReportsView::getSprintReportMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

void SubmittedReportsView::showMenu() {
    system("cls");
    std::cout << "  Submitted Reports Menu\n";
    std::cout << "1 - Show Daily Reports\n";
    std::cout << "2 - Show Sprint Reports\n";
}

void SubmittedReportsView::showReportInfo(Report *report) {
    std::cout << report->getAuthorId() << std::endl;
    std::cout << "Resolved tasks: ";
    for (auto id : report->getTasks())
        std::cout << id << " ";
    std::cout << std::endl;
}

void SubmittedReportsView::showReportMenu() {
    std::cout << "1 - view report text\n";
    std::cout << "2 - Show next report\n";
    std::cout << "3 - exit\n";
}

void SubmittedReportsView::showReportText(Report *report) {
    std::cout << report->getText() << std::endl;
}

void SubmittedReportsView::showSprintReport(SprintDraft *sprintReport) {
    std::cout << sprintReport->getAuthorId() << std::endl;
    std::cout << "Resolved tasks: ";
    for (auto id : sprintReport->getTasks())
        std::cout << id << " ";
    std::cout << std::endl;
}

void SubmittedReportsView::showSpringReportMenu() {
    std::cout << "1 - view report text\n";
    std::cout << "2 - Show next report\n";
    std::cout << "3 - exit\n";
}

void SubmittedReportsView::showSprintReportText(SprintDraft *sprintReport) {
    std::cout << sprintReport->getText() << std::endl;
}
