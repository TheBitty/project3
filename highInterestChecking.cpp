#include "includes/highInterestChecking.h"
#include <iostream>

using namespace std;

const double highInterestChecking::HIGH_INTEREST_RATE = 0.03; // 3%
const double highInterestChecking::HIGH_MIN_BALANCE = 1500.0; // $1500 minimum balance

// Default constructor
highInterestChecking::highInterestChecking() : noServiceChargeChecking() {
    checkingAccount::setInterestRate(HIGH_INTEREST_RATE);
    accountType = "High Interest Checking";
}

// Constructor with account number and balance
highInterestChecking::highInterestChecking(int accNum, double bal)
    : noServiceChargeChecking(accNum, bal) {
    checkingAccount::setInterestRate(HIGH_INTEREST_RATE);
    accountType = "High Interest Checking";
}

// Constructor with the name and balance
highInterestChecking::highInterestChecking(const std::string& name, double bal)
    : noServiceChargeChecking(name, bal) {
    checkingAccount::setInterestRate(HIGH_INTEREST_RATE);
    accountType = "High Interest Checking";
}