#ifndef BEGINNING_C_PLUS_PLUS_INHERITANCE_CHECKINGACCOUNT_H_
#define BEGINNING_C_PLUS_PLUS_INHERITANCE_CHECKINGACCOUNT_H_

#include "Account.h"
#include <iostream>

class CheckingAccount : public Account {

  friend std::ostream &operator<<(std::ostream &os, const CheckingAccount account){
    os << "[Trust Account: " << account.name << ": " << account.balance << " ]";
    return os;
  };

 private:
  static constexpr const char *def_name = "Unnamed Checking Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_withdraw_fee = 1.50;

 public:
  CheckingAccount(std::string name, double balance) : Account{name, balance} {};
  ~CheckingAccount() = default;

  bool withdraw(double amount) {
    amount += def_withdraw_fee;
    return Account::withdraw(amount);
  };

};

#endif
