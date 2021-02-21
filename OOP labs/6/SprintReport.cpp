#include "SprintReport.h"


SprintReport::SprintReport(size_t _authorID) :
        Report(_authorID) {}

void SprintReport::addSubordinateReport(SprintReport *report) {
    subordinateReports.push_back(report);
}


const std::vector<SprintReport *> &SprintReport::getSubordinateReports() {
    return subordinateReports;
}
