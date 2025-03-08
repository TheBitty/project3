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

bool serviceChargeChecking::withdraw(const double amount) {
 const bool success = checkingAccount::withdraw(amount);
 if (success) {
  checksWritten++;  // Note: You probably don't want to increment checks on withdrawals
 }
 return success;
}

void serviceChargeChecking::print() const {
 checkingAccount::print();
}

bool serviceChargeChecking::writeCheck(const double amount) {
 return checkingAccount::writeCheck(amount);
}

void serviceChargeChecking::createMonthlyStatement() {
}

auto serviceChargeChecking::getChecksWritten() const -> int {
 return checksWritten; ;
}
