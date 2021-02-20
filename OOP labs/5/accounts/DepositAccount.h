#pragma once

#include "Account.h"
#include "../DateListener.h"

class DepositAccount : public Account, public DateListener {
public:
    DepositAccount(long id, User *owner, long term, double startAmount, double partPerDay);

    double getPartPerDay();

    void add(double amount) override;

    void dec(double amount) override;

    void onDayEnd() override;

    void onMonthEnd() override;

private:
    long daysLeft;
    double balance;
    double partPerDay;
};
