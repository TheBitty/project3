cmake_minimum_required(VERSION 3.30)
project(Project2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project2 main.cpp
        bankAccount.h
        checkingAccount.h
        savingsAccount.h)
