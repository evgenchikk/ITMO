#include "SprintReport.h"

SprintReport::SprintReport(size_t _authorId) :
        SprintDraft(_authorId) {}

bool SprintReport::getDraftStatus(size_t draftAuthorId) {
    for (auto t : getSubordinateReports())
        if (t->getAuthorId() == draftAuthorId)
            return true;
    return false;
}
