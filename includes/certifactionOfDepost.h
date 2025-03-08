// certificateOfDeposit.h
#pragma once
#ifndef CERTIFICATE_OF_DEPOSIT_H
#define CERTIFICATE_OF_DEPOSIT_H

#include "bankAccount.h"

class certificateOfDeposit : public bankAccount {
private:
    static const double EARLY_WITHDRAWAL_PENALTY;
    double interestRate;
    int maturityMonths;
    int currentMonth;
    
public:
    // Constructors
    certificateOfDeposit();
    certificateOfDeposit(int accNum, double bal);
    explicit certificateOfDeposit(const std::string& name, double bal = 0.0,
                         double rate = 0.03, int months = 6);
    
    // Accessors
    [[nodiscard]] double getInterestRate() const override;
    [[nodiscard]] int getMaturityMonths() const;
    [[nodiscard]] int getCurrentMonth() const;
    [[nodiscard]] bool isMatured() const;
    
    // Implementation of pure virtual functions
    bool withdraw(double amount) override;
    void createMonthlyStatement();
    
    // Override print method
    void print() const override;
};

#endif // CERTIFICATE_OF_DEPOSIT_H