#include "includes/serviceChargeChecking.h"
#include <iostream>

using namespace std;

const double serviceChargeChecking::MONTHLY_SERVICE_CHARGE = 5.0;
const int serviceChargeChecking::MAX_CHECKS = 10;

// Default constructor with the default values
serviceChargeChecking::serviceChargeChecking() :
    checkingAccount(), checksWritten(0) {
    checkingAccount::setInterestRate(0.0);
    setMinBalance(0.0);
    setFeeCharges(MONTHLY_SERVICE_CHARGE);
    accountType = "Service Charge Checking";
}

serviceChargeChecking::serviceChargeChecking(int accNum, double bal) :
    checkingAccount(accNum, bal, 0.0, 0.0, MONTHLY_SERVICE_CHARGE), checksWritten(0) {
    accountType = "Service Charge Checking";
}

serviceChargeChecking::serviceChargeChecking(const std::string& name, double bal) :
    checkingAccount(name, bal, 0.0, 0.0, MONTHLY_SERVICE_CHARGE), checksWritten(0) {
    accountType = "Service Charge Checking";
}

bool serviceChargeChecking::withdraw(const double amount) {
    return checkingAccount::withdraw(amount);
}

bool serviceChargeChecking::writeCheck(const double amount) {
    bool success = checkingAccount::writeCheck(amount);
    if (success) {
        checksWritten++;
    }
    return success;
}

void serviceChargeChecking::createMonthlyStatement() const {
    cout << "Service Charge: $" << MONTHLY_SERVICE_CHARGE << ", Checks: "
         << checksWritten << "/" << MAX_CHECKS << endl;
}

int serviceChargeChecking::getChecksWritten() const {
    return checksWritten;
}

void serviceChargeChecking::print() const {
    checkingAccount::print();
    cout << "Type: Service Charge Checking" << endl;
    cout << "Fee: $" << MONTHLY_SERVICE_CHARGE << ", Checks: "
         << checksWritten << "/" << MAX_CHECKS << endl;
}