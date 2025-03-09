cmake_minimum_required(VERSION 3.30)
project(Project3)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project2 src/main.cpp
        src/includes/bankAccount.h
        src/includes/checkingAccount.h
        src/includes/savingsAccount.h
        src/includes/serviceChargeChecking.h
        src/serviceChargeChecking.cpp
        src/includes/noServiceChargeChecking.h
        src/includes/highInterestSavings.h
        src/includes/highInterestChecking.h
        src/includes/certificationOfDeposit.h
        src/noServiceChargeChecking.cpp
        src/highInterestChecking.cpp
        src/highInterestSavings.cpp
        src/certificateOfDeposit.cpp)
