#pragma once

#include "accounts/Account.h"

class AccountCreatedListener {
public:
    virtual void onCreated(Account *account) = 0;
};
