#ifndef BEGINNING_C_PLUS_PLUS_INHERITANCE_ACCOUNTUTIL_H_
#define BEGINNING_C_PLUS_PLUS_INHERITANCE_ACCOUNTUTIL_H_

#include <vector>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "TrustAccount.h"

class AccountUtil {

 public:
  // Displays Account objects in a  vector of Account objects
  void display(const std::vector<Account> &accounts) {
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto &acc : accounts)
      std::cout << acc << std::endl;
  }

  // Deposits supplied amount to each Account object in the vector
  void deposit(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc : accounts) {
      if (acc.deposit(amount))
        std::cout << "Deposited " << amount << " to " << acc << std::endl;
      else
        std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
  }

  // Withdraw amount from each Account object in the vector
  void withdraw(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" << std::endl;
    for (auto &acc : accounts) {
      if (acc.withdraw(amount))
        std::cout << "Withdrew " << amount << " from " << acc << std::endl;
      else
        std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
  }

  // Displays Savings Account objects in a  vector of Savings Account objects
  void display(const std::vector<SavingsAccount> &accounts) {
    std::cout << "\n=== Savings Accounts ====================================" << std::endl;
    for (const auto &acc : accounts)
      std::cout << acc << std::endl;
  }

  // Deposits supplied amount to each Savings Account object in the vector
  void deposit(std::vector<SavingsAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts ==========================" << std::endl;
    for (auto &acc : accounts) {
      if (acc.deposit(amount))
        std::cout << "Deposited " << amount << " to " << acc << std::endl;
      else
        std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
  }

  // Withdraw supplied amount from each Savings Account object in the vector
  void withdraw(std::vector<SavingsAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ======================" << std::endl;
    for (auto &acc : accounts) {
      if (acc.withdraw(amount))
        std::cout << "Withdrew " << amount << " from " << acc << std::endl;
      else
        std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
  }

  // Displays TrustAccount objects in a vector of TrustAccount objects
  void display(const std::vector<TrustAccount> &accounts) {
    std::cout << "\n=== Trust Accounts ====================================" << std::endl;
    for (const auto &acc : accounts)
      std::cout << acc << std::endl;
  }

  // Deposits supplied amount to each TrustAccount object in the vector
  void deposit(std::vector<TrustAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to Trust Accounts ==========================" << std::endl;
    for (auto &acc : accounts) {
      if (acc.deposit(amount))
        std::cout << "Deposited " << amount << " to " << acc << std::endl;
      else
        std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
  }

  // Withdraw supplied amount from each TrustAccount object in the vector
  void withdraw(std::vector<TrustAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Trust Accounts ======================" << std::endl;
    for (auto &acc : accounts) {
      if (acc.withdraw(amount))
        std::cout << "Withdrew " << amount << " from " << acc << std::endl;
      else
        std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
  }

  // Displays TrustAccount objects in a vector of TrustAccount objects
  void display(const std::vector<CheckingAccount> &accounts) {
    std::cout << "\n=== Checking Accounts ====================================" << std::endl;
    for (const auto &acc : accounts)
      std::cout << acc << std::endl;
  }

  // Deposits supplied amount to each TrustAccount object in the vector
  void deposit(std::vector<CheckingAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to Checking Accounts ==========================" << std::endl;
    for (auto &acc : accounts) {
      if (acc.deposit(amount))
        std::cout << "Deposited " << amount << " to " << acc << std::endl;
      else
        std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
  }

  // Withdraw supplied amount from each TrustAccount object in the vector
  void withdraw(std::vector<CheckingAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Checking Accounts ======================" << std::endl;
    for (auto &acc : accounts) {
      if (acc.withdraw(amount))
        std::cout << "Withdrew " << amount << " from " << acc << std::endl;
      else
        std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
  }

};

#endif
