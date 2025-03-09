// highInterestSavings.h
//
// Created by leo g on 03/05/25.
#pragma once
#ifndef HIGH_INTEREST_SAVINGS_H
#define HIGH_INTEREST_SAVINGS_H

#include "savingsAccount.h"

class highInterestSavings : public savingsAccount {
private:
    static const double HIGH_INTEREST_RATE;
    static const double MIN_BALANCE;

public:
    // Constructors
    highInterestSavings();
    highInterestSavings(int accNum, double bal);
    explicit highInterestSavings(const std::string& name, double bal = 0.0);

    // Override virtual functions
    bool withdraw(double amount) override;

    void createMonthlyStatement();


    // Check minimum balance
    [[nodiscard]] bool isBalanceBelowMinimum() const;

    [[nodiscard]] static double getMinimumBalance();

    // Override print method
    void print() const override;
};

#endif // HIGH_INTEREST_SAVINGS_H