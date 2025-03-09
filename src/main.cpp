//
// Created by leo g on 03/08/25.
//
#include <iostream>
#include <string>
#include <utility>
#include "includes/bankAccount.h"
#include "includes/checkingAccount.h"
#include "includes/savingsAccount.h"
#include "includes/serviceChargeChecking.h"
#include "includes/noServiceChargeChecking.h"
#include "includes/highInterestChecking.h"
#include "includes/highInterestSavings.h"
#include "includes/certificationOfDeposit.h"

using namespace std;

int bankAccount::nextAccountNumber = 1001; //moved from our bankAccount.H to try n fix linker error

bankAccount::bankAccount(string name, const double bal) :
    accountNumber(nextAccountNumber++),
    balance(bal),
    accountHolder(std::move(name)),
    accountType("Regular"),
    interestRate(0.0) { }

int main() {
    cout << "Hello admin! Welcome to the LBCC BANK\n";
    cout << "---------------------------------------\n";

    cout << "\n1. Testing Basic Checking Account:\n";
    cout << "---------------------------------------\n";
    checkingAccount checking("John Smith", 1000.0, 0.01, 500.0, 25.0);
    checking.print();
    checking.deposit(200.0);
    checking.writeCheck(300.0);
    checking.withdraw(100.0);
    checking.print();

    cout << "\n2. Testing Service Charge Checking Account:\n";
    cout << "---------------------------------------\n";
    serviceChargeChecking serviceChecking("David Brown", 500.0);
    serviceChecking.print();
    serviceChecking.writeCheck(100.0);
    serviceChecking.writeCheck(50.0);
    serviceChecking.createMonthlyStatement();
    serviceChecking.print();

    cout << "\n3. Testing No Service Charge Checking Account:\n";
    cout << "---------------------------------------\n";
    noServiceChargeChecking noServiceChecking("Michael Clark", 600.0);
    noServiceChecking.print();
    noServiceChecking.deposit(100.0);
    noServiceChecking.withdraw(350.0);
    noServiceChecking.createMonthlyStatement();
    noServiceChecking.print();

    cout << "\n4. Testing High Interest Checking Account:\n";
    cout << "---------------------------------------\n";
    highInterestChecking highInterestCheck("Emily Davis", 2000.0);
    highInterestCheck.print();
    highInterestCheck.withdraw(700.0);
    highInterestCheck.createMonthlyStatement();
    highInterestCheck.print();

    cout << "\n5. Testing Basic Savings Account:\n";
    cout << "---------------------------------------\n";
    savingsAccount savings("Debby White", 1500.0, 0.02);
    savings.print();
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.postInterest();
    savings.print();

    cout << "\n6. Testing High Interest Savings Account:\n";
    cout << "---------------------------------------\n";
    highInterestSavings highSavings("Robert Fill-son", 2500.0);
    highSavings.print();
    highSavings.withdraw(1600.0);
    highSavings.createMonthlyStatement();
    highSavings.print();

    cout << "\n7. Testing Certificate of Deposit Account:\n";
    cout << "---------------------------------------\n";
    certificateOfDeposit cd("Jennifer Bob", 5000.0, 0.04, 12);
    cd.print();
    cd.createMonthlyStatement();
    cd.createMonthlyStatement();
    cd.print();
    cout << "Testing early withdrawal..." << endl;
    cd.withdraw(1000.0);
    cd.print();

    return 0;
}