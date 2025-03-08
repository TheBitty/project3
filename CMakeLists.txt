cmake_minimum_required(VERSION 3.30)
project(Project2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project2 main.cpp
        includes/bankAccount.h
        includes/checkingAccount.h
        includes/savingsAccount.h
        includes/serviceChargeChecking.h
        serviceChargeChecking.cpp
        includes/noServiceChargeChecking.h
        includes/highInterestSavings.h
        includes/highInterestChecking.h
        includes/certifactionOfDepost.h)
