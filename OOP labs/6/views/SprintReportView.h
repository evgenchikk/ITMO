#pragma once

#include "../Report.h"
#include "../SprintReport.h"
#include <string>

class SprintReportView {
public:
    std::string getMenuCommand();

    std::string getText();

    std::string getSubordinatesCommand();

    void showMenu();

    void showReportInfo(Report *report);

    void showSubordinatesReport(SprintDraft *subordinatesReport);

    void showSubordinatesMenu();

    void showReportText(SprintDraft *subordinatesReport);

    void showTeamleadError();
};
