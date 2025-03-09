////
// Created by leo g on 03/06/25.
//
#include "includes/noServiceChargeChecking.h"
#include <iostream>

using namespace std;

const double noServiceChargeChecking::MIN_BALANCE = 500.0;

noServiceChargeChecking::noServiceChargeChecking() : checkingAccount() {
    checkingAccount::setInterestRate(0.01);
    checkingAccount::setMinBalance(MIN_BALANCE);
    checkingAccount::setFeeCharges(0.0);
    accountType = "No Service Charge Checking";
}

noServiceChargeChecking::noServiceChargeChecking(int accNum, double bal) :
    checkingAccount(accNum, bal, 0.01, MIN_BALANCE, 0.0) {
    accountType = "No Service Charge Checking";
}

noServiceChargeChecking::noServiceChargeChecking(const std::string& name, double bal) :
    checkingAccount(name, bal, 0.01, MIN_BALANCE, 0.0) {
    accountType = "No Service Charge Checking";
}

bool noServiceChargeChecking::withdraw(double amount) {
    return checkingAccount::withdraw(amount);
}

bool noServiceChargeChecking::writeCheck(double amount) {
    return checkingAccount::writeCheck(amount);
}

void noServiceChargeChecking::createMonthlyStatement() {
    if (isBalanceBelowMinimum()) {
        cout << "Warning: Account below minimum balance requirement of $"
             << MIN_BALANCE << endl;
    }
    postInterest();
}

bool noServiceChargeChecking::isBalanceBelowMinimum() const {
    return getBalance() < MIN_BALANCE;
}

double noServiceChargeChecking::getMinimumBalance() { // should be returning 500.0
    return MIN_BALANCE;
}

void noServiceChargeChecking::print() const {
    checkingAccount::print();
    cout << "Type: No Service Charge Checking" << endl;
}