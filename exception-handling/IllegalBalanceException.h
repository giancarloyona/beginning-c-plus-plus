#ifndef BEGINNING_C_PLUS_PLUS_ILLEGALBALANCEEXCEPTION_H
#define BEGINNING_C_PLUS_PLUS_ILLEGALBALANCEEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class IllegalBalanceException : public exception {
public:
    IllegalBalanceException() noexcept = default;

    ~IllegalBalanceException() = default;

    const char *what() const noexcept override {
        return "Error! Illegal Balance exception";
    };
};

#endif