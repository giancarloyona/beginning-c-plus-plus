#ifndef BEGINNING_C_PLUS_PLUS_INHERITANCE_ACCOUNT_H_
#define BEGINNING_C_PLUS_PLUS_INHERITANCE_ACCOUNT_H_

#include <iostream>
#include <string>

using namespace std;

class Account {

  friend std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << " ]";
    return os;
  }

 private:
  static constexpr const char *def_name = "Unnamed Account";
  static constexpr const int def_balance = 0.0;

 protected:
  std::string name;
  double balance;

 public:
  Account(std::string name = def_name, double balance = def_balance) : name{name}, balance{balance} {};
  ~Account()=default;

  double getBalance() const {
    return balance;
  }

  bool withdraw(double amount) {
    if (balance - amount < 0) {
      return false;
    }
    balance -= amount;
    return true;
  }

  bool deposit(double amount) {
    if (amount < 0) {
      return false;
    }
    balance += amount;
    return true;
  }

};

#endif
