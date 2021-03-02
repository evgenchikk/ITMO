#pragma once

#include "../Report.h"
#include <string>

class DailyReportView {
public:
    std::string getMenuCommand();

    std::string getText();

    void showMenu();

    void showReportInfo(Report *report);
};
