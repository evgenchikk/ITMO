#pragma once

#include "accounts/Account.h"

class Transaction {
public:
    Account *getAccountToAdd();

    Account *getAccountToDec();

    double getAmount() const;

    bool tryMake();

    bool tryRevert();

    class TransactionBuilder {
    public:
        TransactionBuilder(double maxAmountForNonTrusted);

        TransactionBuilder *addAccount(Account *account);

        TransactionBuilder *decAccount(Account *account);

        TransactionBuilder *amount(double amount);

        Transaction *build();

        private:
            void throwIfProhibited(Account *account, double amount);

            double maxAmountForNonTrusted;
            Transaction *transaction;
        };

private:
    Transaction();

    bool isMade = false;
    double amount = 0;
    Account *accountToAdd;
    Account *accountToDec;
};
