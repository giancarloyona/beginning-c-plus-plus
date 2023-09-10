#include <iostream>
#include <fstream>
#include <string>

bool is_substring(const std::string& word, const std::string& substring) {
    if (word.find(substring) != std::string::npos) {
        return true;
    }
    return false;
}


int main() {

    std::fstream fs;
    fs.open("io-and-streams/data/romeoandjuliet.txt");

    int num_words{};
    std::string query;
    int times_found{0};
    std::string word;

    if (!fs) {
        std::cerr << "Can't open the file!";
        std::exit(1);
    } else {
        std::cout << "Enter the substring to search for:";
        std::cin >> query;
        while (!fs.eof()) {
            num_words++;
            fs >> word;
            if (is_substring(word, query)) {
                times_found++;
            }
        }
    }

    fs.close();
    std::cout << num_words << " were searched..." << std::endl;
    std::cout << "The substring " << query << " was found " << times_found << " times" << std::endl;
    return 0;
}