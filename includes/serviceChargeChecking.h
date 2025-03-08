// serviceChargeChecking.h
#pragma once
#ifndef SERVICE_CHARGE_CHECKING_H
#define SERVICE_CHARGE_CHECKING_H
#include "checkingAccount.h"

class serviceChargeChecking final : public checkingAccount {
private:
    static const double MONTHLY_SERVICE_CHARGE;
    static const int MAX_CHECKS;
    int checksWritten = 0;

public:
    serviceChargeChecking();
    serviceChargeChecking(int accNum, double bal) = delete;
    explicit serviceChargeChecking(const std::string& name, double bal = 0.0) = delete;

    bool withdraw(double amount) override = 0;
    bool writeCheck(double amount) override;

    static void createMonthlyStatement();
    [[nodiscard]] int getChecksWritten() const;
    void print() const override;
};
#endif // SERVICE_CHARGE_CHECKING_H