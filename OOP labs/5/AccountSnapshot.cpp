//#pragma once

#include "AccountSnapshot.h"

AccountSnapshot::AccountSnapshot(double amount) {
    this->amount = amount;
}

double AccountSnapshot::getAmount() const {
    return amount;
}
