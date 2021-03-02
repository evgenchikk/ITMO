#include "ReportMenuView.h"
#include <iostream>

std::string ReportMenuView::getMenuCommand() {
    std::string input;
    getline(std::cin, input);
    return input;
}

void ReportMenuView::showGuestsError() {
    std::cout << "Guests can't edit reports!\n";
}

void ReportMenuView::showMenu() {
    system("cls");
    std::cout << "  Reports Menu\n";
    std::cout << "1 - Daily Report\n";
    std::cout << "2 - Sprint Draft\n";
    std::cout << "3 - Submitted Reports\n";
    std::cout << "4 - Sprint Report\n";
    std::cout << "e - Exit\n";
    std::cout << std::endl;
}
