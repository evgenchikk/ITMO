#include "ReportList.h"

void ReportList::addDailyReport(Report *report) {
    dailyReports.push_back(report);
}

void ReportList::addSprintReport(SprintDraft *report) {
    sprintReports.push_back(report);
}

const std::vector<Report *> &ReportList::getDailyReports() {
    return dailyReports;
}

const std::vector<SprintDraft *> &ReportList::getSprintReports() {
    return sprintReports;
}
