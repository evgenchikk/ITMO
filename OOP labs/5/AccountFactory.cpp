#include "AccountFactory.h"
#include "accounts/DebitAccount.h"
#include "accounts/DepositAccount.h"
#include "accounts/CreditAccount.h"

AccountFactory::AccountFactory(
        double commission,
        AccountCreatedListener *accountCreated,
        DateController *dateController
) {
    this->id = 0;
    this->commission = commission;
    this->accountCreated = accountCreated;
    this->dateController = dateController;
}

Account *AccountFactory::createDepositAccount(User *owner, long term, double startAmount) {
    auto *account = new DepositAccount(id++, owner, term, startAmount, 5.0 / 365 / 100);
    accountCreated->onCreated(account);
    dateController->addDateListener(account);

    return account;
}

Account *AccountFactory::createDebitAccount(User *owner, double percentPerYear) {
    auto *account = new DebitAccount(id++, owner, 5.0 / 365 / 100);
    accountCreated->onCreated(account);
    dateController->addDateListener(account);

    return account;
}

Account *AccountFactory::createCreditAccount(User *owner, double creditLimit) {
    auto *account = new CreditAccount(id++, owner, creditLimit, commission);
    accountCreated->onCreated(account);

    return account;
}
