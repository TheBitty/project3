// main.cpp
#include <iostream>
#include <string>
#include <utility>
#include "bankAccount.h"
#include "checkingAccount.h"
#include "savingsAccount.h"

using namespace std;

bankAccount::bankAccount(string name, const double bal) : // to fix a linker error
    accountNumber(nextAccountNumber++),
    balance(bal),
    accountHolder(std::move(name)),
    accountType("Regular"),  // Default account type
    interestRate(0.0) { }

int main() {
    // Create a checking account
    cout << "Hello admin! Welcome to the LBCC BANK\n";
    cout << "---------------------------------------\n";
    cout << "Creating a checking and savings account:\n";
    cout << "---------------------------------------\n";

    checkingAccount checking("John Smith", 1000.0, 0.01, 500.0, 25.0);
    checking.print();

    cout << "\nDepositing $500.00...\n";
    checking.deposit(500.0);
    checking.print();

    cout << "\nWriting a check for $700.00...\n";
    checking.writeCheck(700.0);
    checking.print();

    cout << "\nWithdrawing $900.00 (should trigger minimum balance warning)...\n";
    checking.withdraw(900.0);
    checking.print();

    cout << "\nPosting interest...\n";
    checking.postInterest();
    checking.print();

    // Create a savings account
    cout << "\n\nCreating and testing a savings account:\n";
    cout << "---------------------------------------\n";

    savingsAccount savings("Jane Smith", 2000.0, 0.03);
    savings.print();

    cout << "\nDepositing $1000.00...\n";
    savings.deposit(1000.0);
    savings.print();

    cout << "\nWithdrawing $500.00...\n";
    savings.withdraw(500.0);
    savings.print();

    cout << "\nPosting interest...\n";
    savings.postInterest();
    savings.print();

    return 0;
}