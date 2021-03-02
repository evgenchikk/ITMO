#pragma once

#include <string>

class MainMenuView {
public:
    std::string getMenuCommand();

    void showMenu();

    void showCurrentUser(int userId);
};
