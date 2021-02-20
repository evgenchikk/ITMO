#include "DepositAccount.h"

DepositAccount::DepositAccount(
        long id,
        User *owner,
        long term,
        double startAmount,
        double partPerDay
) : Account(id, owner, startAmount) {
    this->daysLeft = term;
    this->partPerDay = partPerDay;
}

double DepositAccount::getPartPerDay() {
    return partPerDay;
}

void DepositAccount::add(double amount) {
    this->amount = amount;
}

void DepositAccount::dec(double amount) {
    if (daysLeft != 0) {
        throw std::runtime_error("Early withdrawal");
    }
    if (this->amount - amount < 0) {
        throw std::runtime_error("Negative money");
    }

    this->amount -= amount;
}

void DepositAccount::onDayEnd() {
    daysLeft--;
    balance += amount * partPerDay;
}

void DepositAccount::onMonthEnd() {
    amount += balance;
    balance = 0;
}
