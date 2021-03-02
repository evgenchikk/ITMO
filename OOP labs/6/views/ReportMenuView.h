#pragma once

#include <string>

class ReportMenuView {
public:
    std::string getMenuCommand();

    void showGuestsError();

    void showMenu();
};
