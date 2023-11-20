#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


bool is_palindrome(const std::string &s) {
    std::deque<char> to_check{};

    // ignores non-alpha characters
    for (char c: s) {
        if (isalpha(c)) {
            to_check.push_back(std::toupper(c));
        }

    }

    size_t str_size = to_check.size() - 1;
    for (auto i = 0; i < to_check.size() / 2; i++) {
        if (to_check.at(i) != to_check.at(str_size - i)) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << std::left;
    std::cout << std::setw(10) << "Result" << std::setw(50) << "String" << std::endl;

    std::vector<std::string> strings{"A Santa at Nasa", "abc", "aa", "C++", "abab", "abba"};

    for (auto c: strings) {
        std::cout << std::setw(10) << is_palindrome(c) << std::setw(50) << c << std::endl;
    }
}