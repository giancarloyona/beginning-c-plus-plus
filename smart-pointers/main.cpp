#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
private:
    int data;
public:
    Test(int data) : data{data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }

    int get_data() const { return data; }

    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    int data{};
    for (int i = 0; i < num; i++) {
        std::cout << "Enter data point [" << i+1 << "] : ";
        std::cin >> data;
        vec.push_back(std::make_shared<Test>(data));
    }
};

void display(const std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "Displaying vector data" << std::endl;
    std::cout << "=======================" << std::endl;
    for (const auto &t: vec) {
        std::cout << t->get_data() << std::endl;
    }
    std::cout << "=======================" << std::endl;
}

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();

    int num;
    std::cout << "How many data points do you want to enter: ";
    std::cin >> num;

    fill(*vec_ptr, num);
    display(*vec_ptr);

    return 0;
}