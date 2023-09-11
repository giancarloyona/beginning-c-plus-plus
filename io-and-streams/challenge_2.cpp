#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    std::string answer;
};

int get_score(std::string ANSWER, std::string std_ans) {
    int score{0};

    for (int i = 0; i < ANSWER.length(); i++) {
        if (ANSWER[i] == std_ans[i]) {
            score++;
        }
    }

    return score;
}

int main() {
    std::string line{};
    std::string ANSWER{};
    std::vector<Student> students;

    std::fstream fs;
    fs.open("io-and-streams/data/responses.txt");

    if (!fs) {
        std::cerr << "Can't open the file!";
        std::exit(1);
    } else {
        fs >> ANSWER;
        while (std::getline(fs, line)) {
            Student student{};
            fs >> student.name;
            fs >> student.answer;
            students.push_back(student);
        }
    }
    fs.close();

    int score{0};
    double total{0};
    double avg{0.0};

    std::cout << std::setw(20) << std::left << "Student";
    std::cout << std::setw(10) << std::right << "Score" << std::endl;
    std::cout << "------------------------------" << std::endl;
    for (int i{0}; i < students.size(); i++) {
        std::string std_ans = students.at(i).answer;
        score = get_score(ANSWER, std_ans);
        total += score;

        std::cout << std::setw(20) << std::left << students.at(i).name;
        std::cout << std::setw(10) << std::right << score << std::endl;
    }
    avg = total / students.size();
    std::cout << "------------------------------" << std::endl;
    std::cout << std::setw(20) << std::left << "Average score";
    std::cout << std::setw(10) << std::right << std::setprecision(3) << avg;

    return 0;
}