#pragma once

#include "Report.h"

class SprintDraft : public Report {
    std::vector<SprintDraft *> subordinateReports;
public:
    SprintDraft(size_t _authorId);

    void addSubordinateReport(SprintDraft *report);

    const std::vector<SprintDraft *> &getSubordinateReports();
};
