#include "DailyReportView.h"
#include <iostream>

std::string DailyReportView::getMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

std::string DailyReportView::getText() {
    std::string input;
    std::cout << "Text: ";
    getline(std::cin, input);
    return input;
}

void DailyReportView::showMenu() {
    system("cls");
    std::cout << "  Daily Report Menu\n";
    std::cout << "1 - Add text to report\n";
    std::cout << "2 - Show report info\n";
    std::cout << "3 - Close report and submit\n";
}

void DailyReportView::showReportInfo(Report *report) {
    std::cout << "Resolved tasks: ";
    for (auto t : report->getTasks())
        std::cout << t << " ";
    std::cout << std::endl;
    std::cout << report->getText() << std::endl;
}
