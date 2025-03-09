//
// Created by leo g on 03/07/25.
//
#include "includes/highInterestSavings.h"
#include <iostream>

using namespace std;

const double highInterestSavings::HIGH_INTEREST_RATE = 0.05;
const double highInterestSavings::MIN_BALANCE = 1000.0;

highInterestSavings::highInterestSavings() : savingsAccount() {
    savingsAccount::setInterestRate(HIGH_INTEREST_RATE);
    accountType = "High Interest Savings";
}

highInterestSavings::highInterestSavings(int accNum, double bal) :
    savingsAccount(accNum, bal, HIGH_INTEREST_RATE) {
    accountType = "High Interest Savings";
}

highInterestSavings::highInterestSavings(const std::string& name, double bal) :
    savingsAccount(name, bal, HIGH_INTEREST_RATE) {
    accountType = "High Interest Savings";
}

bool highInterestSavings::withdraw(const double amount) {
    bool success = savingsAccount::withdraw(amount);
    if (success && isBalanceBelowMinimum()) {
        cout << "Warning: Balance below minimum after withdrawal" << endl;
    }
    return success;
}

void highInterestSavings::createMonthlyStatement() {
    if (isBalanceBelowMinimum()) {
        cout << "Warning: Account below minimum balance requirement of $"
             << MIN_BALANCE << endl;
    }
    postInterest();
}

bool highInterestSavings::isBalanceBelowMinimum() const {
    return balance < MIN_BALANCE;
}

double highInterestSavings::getMinimumBalance() {
    return MIN_BALANCE;
}

void highInterestSavings::printAdditionalInfo() const {
    cout << "Account Type: High Interest Savings" << endl;
    cout << "Minimum Balance Requirement: $" << fixed << setprecision(2)
         << MIN_BALANCE << endl;

    if (isBalanceBelowMinimum()) {
        cout << R"(*** The account is below minimum balance ***)" << endl;
    }
}