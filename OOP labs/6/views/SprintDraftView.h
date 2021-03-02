#pragma once

#include "../Report.h"
#include "../SprintDraft.h"
#include <string>

class SprintDraftView {
public:
    std::string getMenuCommand();

    std::string getText();

    std::string getSubordinatesCommand();

    void showMenu();

    void showReportInfo(Report *report);

    void showSubordinatesReport(SprintDraft *subordinatesReport);

    void showSubordinatesMenu();

    void showReportText(SprintDraft *subordinatesReport);
};
