#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_numbers(const vector<int> &numbers);
void add_number(vector<int> &numbers, int n);
void print_mean(const vector<int> &numbers);
void print_smallest(const vector<int> &numbers);
void print_largest(const vector<int> &numbers);

int main () {
  char choice{};
  bool valid_choice{true};
  vector<int> numbers{};

  do {
    cout << "\nMenu: " << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display the mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (toupper(choice)) {
      case 'P': {
        print_numbers(numbers);
        break;
      }
      case 'A': {
        int n{};
        cout << "Enter an integer to add to the list: ";
        cin >> n;
        add_number(numbers, n);
        break;
      }
      case 'M': {
        print_mean(numbers);
        break;
      }
      case 'S': {
        print_smallest(numbers);
        break;
      }
      case 'L': {
        print_largest(numbers);
        break;
      }
      case 'Q': {
        valid_choice = false;
        break;
      }
      default: {
        cout << "Invalid choice! Try again." << endl;
        break;
      }
    }
  } while (valid_choice);
}

void print_numbers(const vector<int> &numbers){
  if (numbers.empty()) {
    cout << "[] - the list is empty" << endl;
  } else {
    cout << "[ ";
    for (int i : numbers) {
      cout << i << " ";
    }
    cout << "]" << endl;
  }
}

void add_number(vector<int> &numbers, int n){
  numbers.push_back(n);
  cout << n << " added" << endl;
}

void print_mean(const vector<int> &numbers){
  if (numbers.empty()) {
    cout << "Unable to calculate the mean - no data" << endl;
  } else {
    float mean{};
    int sum{};

    for (int i : numbers) {
      sum += i;
    }
    mean = static_cast<float>(sum) / static_cast<float>(numbers.size());
    cout << "The calculated mean is: " << mean << endl;
  }
}

void print_smallest(const vector<int> &numbers){
  if (numbers.empty()) {
    cout << "Unable to determine the smallest number - no data" << endl;
  } else {
    cout << "The smallest number is: " << *min_element(numbers.begin(), numbers.end()) << endl;
  }
}

void print_largest(const vector<int> &numbers){
  if (numbers.empty()) {
    cout << "Unable to determine the largest number - no data" << endl;
  } else {
    cout << "The largest number is: " << *max_element(numbers.begin(), numbers.end()) << endl;
  }
}