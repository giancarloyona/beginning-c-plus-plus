#include <iostream>
using namespace std;

const double cost_small_room = 25.0;
const double cost_large_room = 35.0;
const double sale_tax = 0.06;
const int estimate_prize_days = 30;

int main(){

  int number_small_rooms{0};
  int number_large_rooms{0};
  double total{0.0};
  double tax{0.0};

  cout << "Hello, welcome to Frank\'s Carpet Cleaning Service" << endl;
  cout << "How many small rooms would you like cleaned? ";
  cin >> number_small_rooms;
  cout << "How many large rooms would you like cleaned? ";
  cin >> number_large_rooms;

  cout << "\nEstimate for carpet cleaning service" << endl;
  cout << "Number of small rooms: " << number_small_rooms;
  cout << "Number of large rooms: " << number_large_rooms;
  cout << "Price per small room: $" << cost_small_room << endl;
  cout << "Price per large room: $" << cost_large_room << endl;

  total = (number_small_rooms * cost_small_room) + (number_large_rooms * cost_large_room);
  tax = total * sale_tax;

  cout << "Cost: $" << total << endl;
  cout << "Tax: $" << tax << endl;
  cout << "===================" << endl;

  total += tax;
  cout << "Total estimate: $" << total << endl;

  cout << "This estimate is valid for " << estimate_prize_days << " days.";
}
