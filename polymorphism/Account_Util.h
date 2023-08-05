#ifndef BEGINNING_C_PLUS_PLUS_POLYMORPHISM_ACCOUNT_UTIL_H_
#define BEGINNING_C_PLUS_PLUS_POLYMORPHISM_ACCOUNT_UTIL_H_

#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);

#endif