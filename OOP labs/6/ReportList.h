#pragma once

#include "SprintReport.h"


class ReportList {
    std::vector<Report *> dailyReports;
    std::vector<SprintReport *> sprintReports;
public:

    void addDailyReport(Report *report);

    void addSprintReport(SprintReport *report);

    const std::vector<Report *> &getDailyReports();

    const std::vector<SprintReport *> &getSprintReports();
};
