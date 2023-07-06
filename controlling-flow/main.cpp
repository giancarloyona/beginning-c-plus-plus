#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  char choice{};
  bool validChoice{true};
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
    choice = toupper(choice);

    switch (toupper(choice)) {
      case 'P': {
        if (numbers.empty()) {
          cout << "[] - the list is empty" << endl;
        } else {
          // printing the vector data
          cout << "[ ";
          for (int i : numbers) {
            cout << i << " ";
          }
          cout << "]" << endl;
        }
        break;
      }
      case 'A': {
        int numToAdd{};
        cout << "Enter an integer to add to the list: ";
        cin >> numToAdd;
        numbers.push_back(numToAdd);
        cout << numToAdd << " added" << endl;
        break;
      }
      case 'M': {
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
        break;
      }
      case 'S': {
        if (numbers.empty()) {
          cout << "Unable to determine the smallest number - no data" << endl;
        } else {
          cout << "The smallest number is: " << *min_element(numbers.begin(), numbers.end()) << endl;
        }
        break;
      }
      case 'L': {
        if (numbers.empty()) {
          cout << "Unable to determine the largest number - no data" << endl;
        } else {
          cout << "The largest number is: " << *max_element(numbers.begin(), numbers.end()) << endl;
        }
        break;
      }
      case 'Q': {
        cout << "Goodbye..." << endl;
        validChoice = false;
        break;
      }
      default: {
        cout << "Unknown selection, please try again" << endl;
        break;
      }
    }

  } while (validChoice);

  return 0;
}