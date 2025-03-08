#include "includes/certificationOfDeposit.h"
#include <iostream>

using namespace std;

const double certificateOfDeposit::EARLY_WITHDRAWAL_PENALTY = 0.10;

//// Default
certificateOfDeposit::certificateOfDeposit() :
    bankAccount(), interestRate(0.05), maturityMonths(6), currentMonth(0) {
    accountType = "Certificate of Deposit";
}

//account number and balance
certificateOfDeposit::certificateOfDeposit(const int accNum, const double bal) :
    bankAccount(accNum, bal), interestRate(0.03), maturityMonths(6), currentMonth(0) {
    accountType = "Certificate of Deposit";
}

//name, balance, rate, and months
certificateOfDeposit::certificateOfDeposit(const std::string& name, const double bal,
                                           const double rate, const int months) :
    bankAccount(name, "Certificate of Deposit", bal),
    interestRate(rate), maturityMonths(months), currentMonth(0) {
}

double certificateOfDeposit::getInterestRate() const {
    return interestRate;
}

int certificateOfDeposit::getMaturityMonths() const {
    return maturityMonths;
}

int certificateOfDeposit::getCurrentMonth() const {
    return currentMonth;
}

bool certificateOfDeposit::isMatured() const {
    return currentMonth >= maturityMonths;
}

bool certificateOfDeposit::withdraw(const double amount) {
    if (!isMatured()) {
        double penalty = amount * EARLY_WITHDRAWAL_PENALTY;
        std::cout << "Early withdrawal penalty applied: $" << std::fixed
                  << std::setprecision(2) << penalty << std::endl;

        return bankAccount::withdraw(amount + penalty);
    } else {
        // penalty if matured
        return bankAccount::withdraw(amount);
    }
}