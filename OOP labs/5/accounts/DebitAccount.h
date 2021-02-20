#include "Account.h"
#include "../DateListener.h"

class DebitAccount : public Account, public DateListener {
public:
    DebitAccount(long id, User *owner, double partPerDay);

    double getPartPerDay();

    void add(double amount) override;

    void dec(double amount) override;

    void onDayEnd() override;

    void onMonthEnd() override;

private:
    double partPerDay;
    double balance;
};
