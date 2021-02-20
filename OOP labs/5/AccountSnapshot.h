#pragma once

class AccountSnapshot {
public:
    explicit AccountSnapshot(double amount);

    double getAmount() const;

private:
    double amount;
};
