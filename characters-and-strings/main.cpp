#include <iostream>
#include <string>

using namespace std;

int main () {

  bool valid_choice{true};
  int choice{};

  while (valid_choice){

    cout << "OPTIONS" << endl;
    cout << "1 - Encrypt text" << endl;
    cout << "2 - Decrypt text" << endl;
    cout << "0 - Quit" << endl;
    cout << "Type your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {

        string text_to_cipher;
        cout << "Type the text to encrypt: ";
        cin.clear();
        cin.ignore();

        getline(cin, text_to_cipher);

        int key;
        cout << "Type the key to encrypt the text: ";
        cin >> key;

        string ciphertext{};

        for (auto letter : text_to_cipher) {
          int ch;

          if (letter >= 97 && letter <= 122) {
            ch = letter + key;
            if (ch > 122) {
              ch = ch - 122 + 97 - 1;
            }
            ciphertext += static_cast<char>(ch);
          } else if (letter >= 65 && letter <= 90) {
            ch = letter + key;
            if (ch > 90) {
              ch = ch - 90 + 65 - 1;
            }
            ciphertext += static_cast<char>(ch);
          } else {
            ciphertext += static_cast<char>(letter);
          }
        }

        cout << "The encrypted text is: " + ciphertext << endl;
        cout << endl;
        break;
      }
      case 2: {

        string text_to_decipher;
        cout << "Type the text to decrypt: ";
        cin.clear();
        cin.ignore();

        getline(cin, text_to_decipher);

        int key;
        cout << "Type the key to decrypt the text: ";
        cin >> key;

        string original_text{};
        for (auto letter : text_to_decipher) {
          int ch;

          if (letter >= 97 && letter <= 122) {
            ch = letter - key;
            if (ch < 97) {
              ch = ch + 122 - 97 + 1;
            }
            original_text += static_cast<char>(ch);
          } else if (letter >= 65 && letter <= 90) {
            ch = letter - key;
            if (ch < 65) {
              ch = ch + 90 - 65 + 1;
            }
            original_text += static_cast<char>(ch);
          } else {
            original_text += static_cast<char>(letter);
          }
        }

        cout << "The original text is: " + original_text << endl;
        cout << endl;
        break;
      }
      case 0: {
        valid_choice = false;
        break;
      }
      default: {
        cout << "Invalid choice. Try again." << endl;
        break;
      }
    }
  }

}
