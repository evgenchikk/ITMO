#include "Account.h"

Account::Account(long id, User *owner, double amount) {
    this->id = id;
    this->owner = owner;
    this->amount = amount;
}

long Account::getId() {
    return id;
}

User *Account::getOwner() {
    return owner;
}

double Account::getAmount() {
    return amount;
}

AccountSnapshot *Account::createSnapshot() const {
    return new AccountSnapshot(amount);
}

void Account::revert(AccountSnapshot *snapshot) {
    amount = snapshot->getAmount();
}
