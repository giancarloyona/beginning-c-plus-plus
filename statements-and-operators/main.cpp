#include <iostream>
using namespace std;

int main () {

  int num_of_cents{};
  int num_of_dollars{0}, num_of_quarters{0}, num_of_dimes{0}, num_of_nickels{0}, num_of_pennies{0};

  cout << "Enter an amount in cents: ";
  cin >> num_of_cents;
  cout << "You can provide change for this change as follows:" << endl;

  num_of_dollars = num_of_cents / 100;
  num_of_cents %= 100;

  num_of_quarters = num_of_cents / 25;
  num_of_cents %= 25;

  num_of_dimes = num_of_cents / 10;
  num_of_cents %= 10;

  num_of_nickels = num_of_cents / 5;
  num_of_cents %= 5;

  num_of_pennies = num_of_cents / 1;
  num_of_cents %= 1;

  cout << "Dollars: " << num_of_dollars << endl;
  cout << "Quarters: " << num_of_quarters << endl;
  cout << "Dimes: " << num_of_dimes << endl;
  cout << "Nickels: " << num_of_nickels << endl;
  cout << "Pennies: " << num_of_pennies << endl;

  return 0;
}