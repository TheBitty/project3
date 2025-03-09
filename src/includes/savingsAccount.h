// savingsAccount.h
// Created by leo g on 2/27/25.
#pragma once
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "bankAccount.h"

class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    // Constructors
    savingsAccount() : bankAccount(), interestRate(0.0) { }

    savingsAccount(const int accNum, const double bal, const double rate = 0.025) :
        bankAccount(accNum, bal), interestRate(rate) { }

    explicit savingsAccount(const std::string& name, const double bal = 0.0, const double rate = 0.025) :
        bankAccount(name, bal), interestRate(rate) { }

    // Set/Get interest rate
    void setInterestRate(const double rate) override { interestRate = rate; }
    [[nodiscard]] double getInterestRate() const override { return interestRate; }

    // Post interest
    void postInterest() {
        const double interest = balance * interestRate;
        balance += interest;
        std::cout << "Interest posted: $" << std::fixed << std::setprecision(2) << interest << std::endl;
    }

    bool withdraw(const double amount) override {
        return bankAccount::withdraw(amount);
    }

    // print account information
    void print() const override {
        bankAccount::print();
        std::cout << "Account Type: Savings" << std::endl;
        std::cout << "Interest Rate: " << std::fixed << std::setprecision(2)
                  << (interestRate * 100) << "%" << std::endl;
    }
};

#endif // SAVINGSACCOUNT_H