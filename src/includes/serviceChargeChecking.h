// serviceChargeChecking.h
//
// Created by leo g on 03/05/25.
//
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
    serviceChargeChecking(int accNum, double bal);
    explicit serviceChargeChecking(const std::string& name, double bal = 0.0);

    bool withdraw(double amount) override;
    bool writeCheck(double amount) override;

    void createMonthlyStatement() const;
    [[nodiscard]] int getChecksWritten() const;

    // Print methods
    void printAdditionalInfo() const override;
};
#endif // SERVICE_CHARGE_CHECKING_H