#include "ChangeUserView.h"
#include <iostream>
#include <string>

int ChangeUserView::getUserId() {
    std::string input;
    system("cls");
    std::cout << "User Id (-1 for Guest): ";
    getline(std::cin, input);
    return stoi(input);
}

void ChangeUserView::showNoSuchError() {
    std::cout << "No such user!\n";
}
