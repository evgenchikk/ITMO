#include "Bank.h"

Bank::Bank(
        double commission,
        double maxAmountForNonTrusted,
        DateController *dateController
) {
    this->accounts = std::vector<Account *>();
    this->maxAmountForNonTrusted = maxAmountForNonTrusted;
    accountFactory = new AccountFactory(
            commission,
            new BankAccountCreatedListener(this),
            dateController
    );
}

AccountFactory *Bank::getAccountFactory() {
    return accountFactory;
}

double Bank::getMaxAmountForNonTrusted() const {
    return maxAmountForNonTrusted;
}

Transaction::TransactionBuilder *Bank::createTransactionBuilder() const {
    return new Transaction::TransactionBuilder(maxAmountForNonTrusted);
}


void Bank::BankAccountCreatedListener::onCreated(Account *account) {
    bank->accounts.push_back(account);
}

Bank::BankAccountCreatedListener::BankAccountCreatedListener(Bank *bank) {
    this->bank = bank;
}
