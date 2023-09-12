#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {

    std::ifstream in_file("io-and-streams/data/romeoandjuliet.txt");
    std::ofstream out_file{"io-and-streams/data/output.txt", std::ios::app};

    if (!out_file or !in_file) {
        std::cerr << "Error reading the files" << std::endl;
        return 1;
    }

    size_t num_line{0};
    std::string line;
    while (std::getline(in_file, line)) {
        if (!line.empty()) {
            out_file << std::setw(10) << std::left << num_line << line << std::endl;
            num_line++;
        } else {
            out_file << line << std::endl;
        }
    }

    std::cout << "File copied!" << std::endl;

    in_file.close();
    out_file.close();

    return 0;
}