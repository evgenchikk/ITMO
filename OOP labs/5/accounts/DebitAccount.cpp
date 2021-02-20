#include "DebitAccount.h"

DebitAccount::DebitAccount(long id, User *owner, double partPerDay) : Account(id, owner, 0) {
    this->partPerDay = partPerDay;
    this->balance = 0;
}

double DebitAccount::getPartPerDay() {
    return partPerDay;
}

void DebitAccount::add(double amount) {
    this->amount += amount;
}

void DebitAccount::dec(double amount) {
    if (this->amount - amount < 0)
    {
        throw std::runtime_error("Negative money");
    }

    this->amount -= amount;
}

void DebitAccount::onDayEnd() {
    balance += amount * partPerDay;
}

void DebitAccount::onMonthEnd() {
    amount += balance;
    balance = 0;
}
