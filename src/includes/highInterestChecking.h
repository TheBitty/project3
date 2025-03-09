// highInterestChecking.h
//
// Created by leo g on 03/05/25.
#pragma once
#ifndef HIGH_INTEREST_CHECKING_H
#define HIGH_INTEREST_CHECKING_H

#include "noServiceChargeChecking.h"

class highInterestChecking : public noServiceChargeChecking {
private:
    static const double HIGH_INTEREST_RATE;
    static const double HIGH_MIN_BALANCE;

public:
    // Constructors
    highInterestChecking();
    highInterestChecking(int accNum, double bal);
    explicit highInterestChecking(const std::string& name, double bal = 0.0);

    // Override virtual functions
    bool withdraw(double amount) override;
    void createMonthlyStatement() override;

    // Get high minimum balance
    [[nodiscard]] static double getHighMinimumBalance();

    // Print methods - use the Template Method pattern
    void printAdditionalInfo() const override;
};

#endif // HIGH_INTEREST_CHECKING_H