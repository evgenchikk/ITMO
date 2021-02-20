#pragma once

#include "../User.h"
#include "../AccountSnapshot.h"

class Account {
public:
    Account(long id, User *owner, double amount);

    long getId();

    User *getOwner();

    double getAmount();

    virtual void add(double amount) = 0;

    virtual void dec(double amount) = 0;

    void revert(AccountSnapshot *snapshot);

    AccountSnapshot *createSnapshot() const;

protected:
    long id;
    User *owner;
    double amount;
};