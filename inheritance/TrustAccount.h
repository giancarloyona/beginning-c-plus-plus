#ifndef BEGINNING_C_PLUS_PLUS_INHERITANCE_TRUSTACCOUNT_H_
#define BEGINNING_C_PLUS_PLUS_INHERITANCE_TRUSTACCOUNT_H_
#include "Account.h"
#include <iostream>

class TrustAccount : public SavingsAccount {
  friend std::ostream &operator<<(std::ostream &os, const TrustAccount account){
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.interestRate << "%]";
    return os;
  };

 private:
  static constexpr const char *def_name = "Unnamed Trust Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 1.50;
  static constexpr double bonus_amount = 50;
  static constexpr double bonus_threshold = 5000;
  static constexpr int max_withdraws = 3;
  static constexpr double max_withdraw_percent = 0.2;

 protected:
  size_t totalWithdraws;

 public:
  TrustAccount(std::string name = def_name, double balance = def_balance, double interestRate = def_int_rate) :
  SavingsAccount{name, balance, interestRate}, totalWithdraws{0} {};

  ~TrustAccount()=default;

  bool deposit(double amount) {
    if (amount >= bonus_threshold) {
      amount+=bonus_amount;
    }
    return Account::deposit(amount);
  };

  bool withdraw(double amount) {
    if (totalWithdraws >= max_withdraws || (amount > balance * max_withdraw_percent)) {
      return false;
    } else {
      totalWithdraws++;
      return true;
    }
  };

};

#endif