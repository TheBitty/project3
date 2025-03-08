#include "includes/serviceChargeChecking.h"
#include <iostream>

using namespace std;

const double serviceChargeChecking::MONTHLY_SERVICE_CHARGE = 5.0;
const int serviceChargeChecking::MAX_CHECKS = 10;

serviceChargeChecking::serviceChargeChecking() :
 checkingAccount(), checksWritten(0) {
  setAccountHolder("None");  //default value for the account holder

 }

bool serviceChargeChecking::writeCheck(double amount) {
 return checkingAccount::writeCheck(amount);
}

void serviceChargeChecking::createMonthlyStatement() {
}

int serviceChargeChecking::getChecksWritten() const {
 return checksWritten; ;
}
