#pragma once

#include "SprintDraft.h"

class ReportList {
    std::vector<Report *> dailyReports;
    std::vector<SprintDraft *> sprintReports;
public:

    void addDailyReport(Report *report);

    void addSprintReport(SprintDraft *report);

    const std::vector<Report *> &getDailyReports();

    const std::vector<SprintDraft *> &getSprintReports();
};
