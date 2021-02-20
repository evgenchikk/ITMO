#pragma once

#include "AccountFactory.h"
#include "vector"
#include "Transaction.h"

class Bank {
public:
    Bank(double commission, double maxAmountForNonTrusted, DateController *dateController);

    AccountFactory *getAccountFactory();

    double getMaxAmountForNonTrusted() const;

    Transaction::TransactionBuilder *createTransactionBuilder() const;

private:
    AccountFactory *accountFactory;
    double maxAmountForNonTrusted;
    std::vector<Account *> accounts;

    class BankAccountCreatedListener : public AccountCreatedListener {
    public:
        explicit BankAccountCreatedListener(Bank *bank);

        void onCreated(Account *account) override;

    private:
        Bank *bank;
    };
};
