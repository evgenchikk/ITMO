#pragma once

#include "../Report.h"
#include "../SprintReport.h"
#include <string>

class SubmittedReportsView {
public:
    std::string getMenuCommand();

    std::string getReportMenuCommand();

    std::string getSprintReportMenuCommand();

    void showMenu();

    void showReportInfo(Report *report);

    void showReportMenu();

    void showReportText(Report *report);

    void showSprintReport(SprintDraft *sprintReport);

    void showSpringReportMenu();

    void showSprintReportText(SprintDraft *sprintReport);
};
