//
// Created by leo g on 2/25/25.
//
// bankAccount.h - Base class for all bank accounts
#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class bankAccount {
protected:
    static int nextAccountNumber;
    int accountNumber;
    double balance;
    string accountHolder;
    string accountType;
    double interestRate;

public:
    virtual ~bankAccount() = default;
    // Default constructor
    bankAccount() :
        accountNumber(nextAccountNumber++),
        balance(0.0),
        accountHolder("None"),
        accountType("None"),
        interestRate(0.0) { }

    // Parameterized constructor
    bankAccount(const int accNum, const double bal) :
        accountNumber(accNum),
        balance(bal),
        accountHolder("None"),
        accountType("None"),
        interestRate(0.0) { }

    // The complete constructor
    bankAccount(string name, string type, const double bal = 0.0, const double rate = 0.0) :
        accountNumber(nextAccountNumber++),
        balance(bal),
        accountHolder(std::move(name)),
        accountType(std::move(type)),
        interestRate(rate) { }

    bankAccount(string name, double bal);

    // Account number methods
    void setAccountNumber(const int num) { accountNumber = num; }
    [[nodiscard]] int getAccountNumber() const { return accountNumber; }

    // Balance accessor
    [[nodiscard]] double getBalance() const { return balance; }

    // Account holder methods
    [[nodiscard]] string getAccountHolder() const { return accountHolder; }
    void setAccountHolder(const string& name) { accountHolder = name; }

    // Interest rate methods
    [[nodiscard]] virtual double getInterestRate() const { return interestRate; }
    virtual void setInterestRate(const double rate) { interestRate = rate; }

    // Deposit method
    virtual void deposit(const double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    // Withdraw method
    virtual bool withdraw(const double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << fixed << setprecision(2) << amount << endl;
            return true;
        }
        cout << "Withdrawal failed: Insufficient funds" << endl;
        return false;
    }

    // Main print method - uses Template Method pattern to avoid duplication
    void print() const {
        cout << "\nAccount Information:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
        printAccountType();
        printInterestRate();
        printAdditionalInfo();
    }

    // Helper print methods that can be overridden by subclasses
    virtual void printAccountType() const {
        cout << "Account Type: " << accountType << endl;
    }

    virtual void printInterestRate() const {
        cout << "Interest Rate: " << fixed << setprecision(2)
             << (interestRate * 100) << "%" << endl;
    }

    virtual void printAdditionalInfo() const {
        // Empty in base class, to be overridden by subclasses
    }
};


#endif // BANKACCOUNT_H