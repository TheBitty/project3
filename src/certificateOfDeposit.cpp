#include "includes/certificationOfDeposit.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double certificateOfDeposit::EARLY_WITHDRAWAL_PENALTY = 0.10;

certificateOfDeposit::certificateOfDeposit() :
    bankAccount(), interestRate(0.05), maturityMonths(6), currentMonth(0) {
    accountType = "Certificate of Deposit";
}

certificateOfDeposit::certificateOfDeposit(const int accNum, const double bal) :
    bankAccount(accNum, bal), interestRate(0.03), maturityMonths(6), currentMonth(0) {
    accountType = "Certificate of Deposit";
}

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
        return bankAccount::withdraw(amount);
    }
}

void certificateOfDeposit::createMonthlyStatement() {
    currentMonth++;

    double interest = balance * (interestRate / 12.0);
    balance += interest;

    cout << "CD Monthly Statement:" << endl;
    cout << "Interest added: $" << fixed << setprecision(2) << interest << endl;
    cout << "Current month: " << currentMonth << " of " << maturityMonths << endl;

    if (isMatured()) {
        cout << "CD has matured. You may now withdraw without penalty." << endl;
    } else {
        cout << "CD matures in " << (maturityMonths - currentMonth) << " months." << endl;
    }
}

void certificateOfDeposit::print() const {
    bankAccount::print();
    cout << "Account Type: Certificate of Deposit" << endl;
    cout << "Interest Rate: " << fixed << setprecision(2)
         << (interestRate * 100) << "%" << endl;
    cout << "Term: " << maturityMonths << " months" << endl;
    cout << "Current Month: " << currentMonth << endl;

    if (isMatured()) {
        cout << "Status: Matured" << endl;
    } else {
        cout << "Status: " << (maturityMonths - currentMonth)
             << " months until maturity" << endl;
    }
}