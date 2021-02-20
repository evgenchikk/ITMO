#include "CreditAccount.h"

CreditAccount::CreditAccount(long id, User *owner, double creditLimit, double commission) : Account(id, owner, 0) {
    this->creditLimit = creditLimit;
    this->commission = commission;
}

double CreditAccount::getCreditLimit() {
    return creditLimit;
}

double CreditAccount::getCommission() {
    return commission;
}

void CreditAccount::add(double amount) {
    this->amount += amount;
}

void CreditAccount::dec(double amount) {
    if (this->amount > -creditLimit) {
        this->amount -= amount;
    } else {
        this->amount -= (amount + amount * commission);
    }
}
