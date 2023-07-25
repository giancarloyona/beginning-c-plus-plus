#ifndef BEGINNING_C_PLUS_PLUS_INHERITANCE_SAVINGSACCOUNT_H_
#define BEGINNING_C_PLUS_PLUS_INHERITANCE_SAVINGSACCOUNT_H_

#include "Account.h"

class SavingsAccount : public Account {

  friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) {
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.interestRate << "%]";
    return os;
  };

 private:
  static constexpr const char *def_name = "Unnamed Savings Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 0.0;

 protected:
  double interestRate;

 public:

  SavingsAccount(std::string name = def_name, double balance =def_balance, double interestRate = def_int_rate) :
  Account{name, balance}, interestRate{interestRate}  {};

  ~SavingsAccount() = default;

  bool deposit(double amount) {
    amount += amount * (interestRate/100);
    return Account::deposit(amount);
  }

};

#endif