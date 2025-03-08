#include "includes/serviceChargeChecking.h"
#include <iostream>

using namespace std;

const double serviceChargeChecking::MONTHLY_SERVICE_CHARGE = 5.0;
const int serviceChargeChecking::MAX_CHECKS = 10;

serviceChargeChecking::serviceChargeChecking() :
 checkingAccount(), checksWritten(0) {
  setAccountHolder("None");  //default value for the account holder

 }

serviceChargeChecking::serviceChargeChecking(int accNum, double bal) {
}

serviceChargeChecking::serviceChargeChecking(const std::string &name, double bal) {
}

bool serviceChargeChecking::withdraw(double amount) {
 return checkingAccount::withdraw(amount);
}

void serviceChargeChecking::print() const {
 checkingAccount::print();
}

bool serviceChargeChecking::writeCheck(double amount) {
 return checkingAccount::writeCheck(amount);
}

void serviceChargeChecking::createMonthlyStatement() {
}

auto serviceChargeChecking::getChecksWritten() const -> int {
 return checksWritten; ;
}
