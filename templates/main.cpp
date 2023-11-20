#include <iostream>
#include <string>

using namespace std;

template <typename T, int N>
class Array {

    int size{N};
    T values[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {
        os << "[ ";
        for (const auto &val: arr.values) {
            os << val << " ";
        }
        os << "]" << std::endl;
        return os;
    }

public:
    Array() = default;
    Array(T init_val) {
        for (auto &item:values) {
            item = init_val;
        }
    }

    void fill(T val) {
        for (auto &item:values) {
            item = val;
        }
    }

    int get_size() const {
        return size;
    }

    T &operator[] (int index) {
        return values[index];
    }

};

int main() {

    Array<int, 5> nums;
    std::cout << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;

    Array<int, 100> nums2;
    std::cout << nums2.get_size() << std::endl;

    Array<string, 5> strings("A");
    std::cout << strings.get_size() << std::endl;
    strings[0] = std::string("B");
    std::cout << strings << std::endl;
}