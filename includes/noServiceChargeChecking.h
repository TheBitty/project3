// noServiceChargeChecking.h
#pragma once
#ifndef NO_SERVICE_CHARGE_CHECKING_H
#define NO_SERVICE_CHARGE_CHECKING_H

#include "checkingAccount.h"

class noServiceChargeChecking : public checkingAccount {
protected:
    static const double MIN_BALANCE;

public:
    noServiceChargeChecking();
    noServiceChargeChecking(int accNum, double bal);
    explicit noServiceChargeChecking(const std::string& name, double bal = 0.0);

    bool withdraw(double amount) override;
    bool writeCheck(double amount) override;

    virtual void createMonthlyStatement();

    [[nodiscard]] bool isBalanceBelowMinimum() const override;
    [[nodiscard]] double getMinimumBalance() const;

    void print() const override;
};
#endif // NO_SERVICE_CHARGE_CHECKING_H