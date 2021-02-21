#pragma once

#include "Report.h"


class SprintReport : public Report {
    std::vector<SprintReport *> subordinateReports;
public:
    SprintReport(size_t _authorID);

    void addSubordinateReport(SprintReport *report);

    const std::vector<SprintReport *> &getSubordinateReports();
};
