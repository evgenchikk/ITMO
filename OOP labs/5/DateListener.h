#pragma once

class DateListener {
public:
    virtual void onDayEnd() = 0;

    virtual void onMonthEnd() = 0;
};
