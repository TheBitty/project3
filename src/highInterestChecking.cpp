//
// Created by leo g on 03/07/25.
//
#include "includes/highInterestChecking.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double highInterestChecking::HIGH_INTEREST_RATE = 0.03;
const double highInterestChecking::HIGH_MIN_BALANCE = 1500.0;

highInterestChecking::highInterestChecking() : noServiceChargeChecking() {
    checkingAccount::setInterestRate(HIGH_INTEREST_RATE);
    accountType = "High Interest Checking";
}

highInterestChecking::highInterestChecking(int accNum, double bal)
    : noServiceChargeChecking(accNum, bal) {
    checkingAccount::setInterestRate(HIGH_INTEREST_RATE);
    accountType = "High Interest Checking";
}

highInterestChecking::highInterestChecking(const std::string& name, double bal)
    : noServiceChargeChecking(name, bal) {
    checkingAccount::setInterestRate(HIGH_INTEREST_RATE);
    accountType = "High Interest Checking";
}

bool highInterestChecking::withdraw(double amount) {
    bool success = noServiceChargeChecking::withdraw(amount);
    if (success && getBalance() < HIGH_MIN_BALANCE) {
        cout << "Warning: Balance below high interest minimum requirement" << endl;
    }
    return success;
}

void highInterestChecking::createMonthlyStatement() {
    if (getBalance() < HIGH_MIN_BALANCE) {
        cout << "Warning: Account below high interest minimum balance requirement of $"
             << HIGH_MIN_BALANCE << endl;
    }
    postInterest();
}

double highInterestChecking::getHighMinimumBalance() {
    return HIGH_MIN_BALANCE;
}

void highInterestChecking::print() const {
    noServiceChargeChecking::print();
    cout << "Type: High Interest Checking" << endl;
    cout << "High Interest Rate: " << fixed << setprecision(2)
         << (HIGH_INTEREST_RATE * 100) << "%" << endl;
    cout << "High Minimum Balance Requirement: $" << HIGH_MIN_BALANCE << endl;

    if (getBalance() < HIGH_MIN_BALANCE) {
        cout << "*** Account is below high interest minimum balance ***" << endl;
    }
}