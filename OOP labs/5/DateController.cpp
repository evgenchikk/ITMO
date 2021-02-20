#include "DateController.h"

void DateController::addDateListener(DateListener *dateListener) {
    dateListeners.push_back(dateListener);
}

void DateController::endDay() {
    for (auto &dateListener : dateListeners) {
        dateListener->onDayEnd();
    }
}

void DateController::endMonth() {
    for (auto &dateListener : dateListeners) {
        dateListener->onMonthEnd();
    }
}

DateController::DateController() {
    dateListeners = std::vector<DateListener *>();
}
