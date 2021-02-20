#pragma once

#include "Account.h"

class CreditAccount : public Account {
public:
    CreditAccount(long id, User *owner, double creditLimit, double commission);

    double getCreditLimit();

    double getCommission();

    void add(double amount) override;

    void dec(double amount) override;


private:
    double creditLimit;
    double commission;
};
