#include "Transaction.h"

Account *Transaction::getAccountToAdd() {
    return accountToAdd;
}

Account *Transaction::getAccountToDec() {
    return accountToDec;
}

double Transaction::getAmount() const {
    return amount;
}

bool Transaction::tryMake() {
    if (isMade) return false;

    AccountSnapshot *addSnapshot;
    if (accountToAdd != nullptr) addSnapshot = accountToAdd->createSnapshot();
    AccountSnapshot *decSnapshot;
    if (accountToDec != nullptr) decSnapshot = accountToDec->createSnapshot();

    try {
        if (accountToAdd != nullptr) accountToAdd->add(amount);
        if (accountToDec != nullptr) accountToDec->dec(amount);
        isMade = true;
        return true;
    } catch (...) {
        if (addSnapshot != nullptr) accountToAdd->revert(addSnapshot);
        if (decSnapshot != nullptr) accountToDec->revert(decSnapshot);
        return false;
    }
}

bool Transaction::tryRevert() {
    if (!isMade || accountToDec == nullptr || accountToAdd == nullptr) return false;

    auto addSnapshot = accountToAdd->createSnapshot();
    auto decSnapshot = accountToDec->createSnapshot();

    try {
        accountToAdd->dec(amount);
        accountToDec->add(amount);
        isMade = false;
        return true;
    } catch (...) {
        accountToAdd->revert(addSnapshot);
        accountToDec->revert(decSnapshot);
        return false;
    }
}

Transaction::Transaction() = default;

Transaction::TransactionBuilder *Transaction::TransactionBuilder::addAccount(Account *account) {
    transaction->accountToAdd = account;
    return this;
}

Transaction::TransactionBuilder *Transaction::TransactionBuilder::decAccount(Account *account) {
    transaction->accountToDec = account;
    return this;
}

Transaction::TransactionBuilder *Transaction::TransactionBuilder::amount(double amount) {
    transaction->amount = amount;
    return this;
}

Transaction *Transaction::TransactionBuilder::build() {
    if (transaction->accountToAdd != nullptr)
        throwIfProhibited(transaction->accountToAdd, transaction->amount);
    if (transaction->accountToDec != nullptr)
        throwIfProhibited(transaction->accountToDec, transaction->amount);

    return transaction;
}

Transaction::TransactionBuilder::TransactionBuilder(double maxAmountForNonTrusted) {
    transaction = new Transaction();
    this->maxAmountForNonTrusted = maxAmountForNonTrusted;
}

void Transaction::TransactionBuilder::throwIfProhibited(Account *account, double amount) {
    if (!account->getOwner()->isTrusted() && amount > maxAmountForNonTrusted) {
        throw std::exception();
    }
}
