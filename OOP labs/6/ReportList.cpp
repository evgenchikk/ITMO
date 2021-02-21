#include "ReportList.h"


void ReportList::addDailyReport(Report *report) {
    dailyReports.push_back(report);
}


void ReportList::addSprintReport(SprintReport *report) {
    sprintReports.push_back(report);
}


const std::vector<Report *> &ReportList::getDailyReports() {
    return dailyReports;
}


const std::vector<SprintReport *> &ReportList::getSprintReports() {
    return sprintReports;
}
