    //
    // Created by leo g on 2/25/25.
    //
    // bankAccount.h
    #pragma once
    #ifndef BANKACCOUNT_H
    #define BANKACCOUNT_H
    #include <iostream>
    #include <string>
    #include <iomanip>

    using namespace std;

    class bankAccount {

    protected: // Protected for derived classes access
        static int nextAccountNumber;
        int accountNumber;
        double balance;
        string accountHolder;
        string accountType;
        double interestRate;

    public:
        virtual ~bankAccount() = default;
        // Default constructor
        bankAccount() :
            accountNumber(nextAccountNumber++),
            balance(0.0),
            accountHolder("None"),
            accountType("None"),
            interestRate(0.0) { }

        // Parameterized constructor
        bankAccount(const int accNum, const double bal) :
            accountNumber(accNum),
            balance(bal),
            accountHolder("None"),
            accountType("None"),
            interestRate(0.0) { }

        // complete constructor
        bankAccount(string  name, string  type, const double bal = 0.0, const double rate = 0.0) :
            accountNumber(nextAccountNumber++),
            balance(bal),
            accountHolder(std::move(name)),
            accountType(std::move(type)),
            interestRate(rate) { }

        bankAccount(string  name, double bal);

        // Set/Get account number
        void setAccountNumber(const int num) { accountNumber = num; }
        [[nodiscard]] int getAccountNumber() const { return accountNumber; }

        // Get balance
        [[nodiscard]] double getBalance() const { return balance; }

        // Get account holder
        [[nodiscard]] string getAccountHolder() const { return accountHolder; }
        void setAccountHolder(const string& name) { accountHolder = name; }

        // Get/Set interest rate
        [[nodiscard]] virtual double getInterestRate() const { return interestRate; }
        virtual void setInterestRate(const double rate) { interestRate = rate; }

        // Deposit money - adding to balance
        virtual void deposit(const double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
            } else {
                cout << "Invalid deposit amount" << endl;
            }
        }

        // Withdraw money - subtracting from balance
        virtual bool withdraw(const double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;  // Corrected: subtract amount from balance
                cout << "Withdrawn: $" << fixed << setprecision(2) << amount << endl;
                return true;
            }
            cout << "Withdrawal failed: Insufficient funds" << endl;
            return false;
        }

        // Print account information
        virtual void print() const {
            cout << "\nAccount Information:" << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder: " << accountHolder << endl;
            cout << "Account Type: " << accountType << endl;
            cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
            cout << "Interest Rate: " << (interestRate * 100) << "%" << endl;
        }
    };

    // Static member definition for nextAccountNumber
    int bankAccount::nextAccountNumber = 1001;

    #endif // BANKACCOUNT_H
