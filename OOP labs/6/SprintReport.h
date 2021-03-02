#pragma once

#include "SprintDraft.h"

class SprintReport : public SprintDraft {
public:
    SprintReport(size_t _authorId);

    bool getDraftStatus(size_t draftAuthorId);
};
