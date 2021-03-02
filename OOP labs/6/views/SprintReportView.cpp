#include "SprintReportView.h"
#include <iostream>

std::string SprintReportView::getMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

std::string SprintReportView::getText() {
    std::string input;
    std::cout << "Text: ";
    getline(std::cin, input);
    return input;
}

std::string SprintReportView::getSubordinatesCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

void SprintReportView::showMenu() {
    system("cls");
    std::cout << "  Sprint Report Menu\n";
    std::cout << "1 - Add text to report\n";
    std::cout << "2 - Show report info\n";
    std::cout << "3 - Show subordinates reports\n";
    std::cout << "4 - Close report and submit\n";
}

void SprintReportView::showReportInfo(Report *report) {
    std::cout << "Resolved tasks: ";
    for (auto t : report->getTasks())
        std::cout << t << " ";
    std::cout << std::endl;
    std::cout << report->getText() << std::endl;
}

void SprintReportView::showSubordinatesReport(SprintDraft *subordinatesReport) {
    std::cout << subordinatesReport->getAuthorId() << std::endl;
    std::cout << "Resolved tasks: ";
    for (auto id : subordinatesReport->getTasks())
        std::cout << id << " ";
    std::cout << std::endl;
}

void SprintReportView::showSubordinatesMenu() {
    std::cout << "1 - view report text\n";
    std::cout << "2 - Show next report\n";
    std::cout << "3 - exit\n";
}

void SprintReportView::showReportText(SprintDraft *subordinatesReport) {
    std::cout << subordinatesReport->getText() << std::endl;
}

void SprintReportView::showTeamleadError() {
    std::cout << "Only teamlead can edit sprint report!\n";
}