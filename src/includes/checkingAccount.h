// Created by leo g on 2/21/25.
// checkingAccount.h
#pragma once
#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include <iostream>
#include <iomanip>
#include "bankAccount.h"

using namespace std;

class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minBalance; // for overdraft
    double feeCharges; // for fees

public:
    // Constructors
    checkingAccount() :
        bankAccount(),
        interestRate(0.0),
        minBalance(0.0),
        feeCharges(5.0) { }

    // Constructor with account number and balance
    explicit checkingAccount(const int accNum, const double bal = 0.0, const double rate = 0.01,
                          const double minBal = 0.0, const double fee = 5.0) :
        bankAccount(accNum, bal),
        interestRate(rate),
        minBalance(minBal),
        feeCharges(fee) { }

    // Constructor with name and account type
    explicit checkingAccount(const string& name, const double bal = 0.0, const double rate = 0.01,
                 const double minBal = 0.0, const double fee = 5.0) :
        bankAccount(name, "Checking", bal),
        interestRate(rate),
        minBalance(minBal),
        feeCharges(fee) { }

    // Interest rate methods
    void setInterestRate(const double rate) override { interestRate = rate; }
    [[nodiscard]] double getInterestRate() const override { return interestRate; }

    // Min balance methods
    void setMinBalance(const double minBal) { minBalance = minBal; }
    [[nodiscard]] double getMinBalance() const { return minBalance; }

    // Fee charges methods
    void setFeeCharges(const double fee) { feeCharges = fee; }
    [[nodiscard]] double getFeeCharges() const { return feeCharges; }

    // Post interest to the account
    void postInterest() {
        const double interest = getBalance() * interestRate;
        deposit(interest);
        cout << "Interest posted: $" << fixed << setprecision(2) << interest << endl;
    }

    // Check if balance is below minimum
    [[nodiscard]] virtual bool isBalanceBelowMinimum() const {
        return getBalance() < minBalance;
    }

    // Apply service charges if balance is below minimum
    void applyServiceCharges() {
        if (isBalanceBelowMinimum()) {
            withdraw(feeCharges);
            cout << "Service charge applied: $" << feeCharges << endl;
        }
    }

    // Write the check
    virtual bool writeCheck(const double amount) {
        if (amount > 0) {
            if (getBalance() >= amount) {
                withdraw(amount);
                cout << "Check written for: $" << amount << endl;

                // Check if transaction causes balance to fall below minimum
                if (isBalanceBelowMinimum()) {
                    cout << "Warning: Balance below minimum after check" << endl;
                }
                return true;
            } else {
                cout << "Check declined: Insufficient funds" << endl;
            }
        }
        return false;
    }

    // Override withdraw method
    bool withdraw(const double amount) override {
        const bool success = bankAccount::withdraw(amount);

        if (success && isBalanceBelowMinimum()) {
            cout << "Warning: Balance below minimum after withdrawal" << endl;
        }

        return success;
    }

    // Override print method
    void print() const override {
        bankAccount::print();
        cout << "Account Type: Checking" << endl;
        cout << "Interest Rate: " << fixed << setprecision(2)
             << (interestRate * 100) << "%" << endl;
        cout << "Minimum Balance: $" << minBalance << endl;
        cout << "Service Charges: $" << feeCharges << endl;

        if (isBalanceBelowMinimum()) {
            cout << "*** Account is below minimum balance ***" << endl;
        }
    }
};

#endif // CHECKING_ACCOUNT_H