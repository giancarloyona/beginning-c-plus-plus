#ifndef BEGINNING_C_PLUS_PLUS_POLYMORPHISM_CHECKING_ACCOUNT_H_
#define BEGINNING_C_PLUS_PLUS_POLYMORPHISM_CHECKING_ACCOUNT_H_

#include <iostream>
#include "Account.h"

class Checking_Account : public Account {

 private:
  static constexpr const char *def_name = "Unnamed Checking Account";
  static constexpr double def_balance = 0.0;
  static constexpr double per_check_fee = 1.5;

 public:
  Checking_Account(std::string name = def_name, double balance = def_balance);
  virtual ~Checking_Account() = default;

  virtual void print(std::ostream &os) const override;
  virtual bool deposit(double) override;
  virtual bool withdraw(double) override;
};

#endif