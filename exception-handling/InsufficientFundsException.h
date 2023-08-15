#ifndef BEGINNING_C_PLUS_PLUS_INSUFFICIENTFUNDSEXCEPTION_H
#define BEGINNING_C_PLUS_PLUS_INSUFFICIENTFUNDSEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class InsufficientFundsException : public exception {
public:
    InsufficientFundsException() noexcept = default;

    ~InsufficientFundsException() = default;

    const char *what() const noexcept override {
        return "Error! Insufficient funds!";
    }
};

#endif