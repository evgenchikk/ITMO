#pragma once

#include "AccountCreatedListener.h"
#include "accounts/Account.h"
#include "DateController.h"

class AccountFactory {
public:
    AccountFactory(
            double commission,
            AccountCreatedListener *accountCreated,
            DateController *dateController
    );

    Account *createDepositAccount(User *owner, long term, double startAmount);

    Account *createDebitAccount(User *owner, double percentPerYear);

    Account *createCreditAccount(User *owner, double creditLimit);

private:
    long id;
    double commission;
    AccountCreatedListener *accountCreated;
    DateController *dateController;
};
