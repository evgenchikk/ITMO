#pragma once

#include "vector"
#include "DateListener.h"

class DateController {
public:
    DateController();

    void addDateListener(DateListener *dateListener);

    void endDay();

    void endMonth();

private:
    std::vector<DateListener *> dateListeners;
};