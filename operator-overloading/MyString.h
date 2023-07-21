#ifndef BEGINNING_C_PLUS_PLUS_OPERATOR_OVERLOADING_MYSTRING_H_
#define BEGINNING_C_PLUS_PLUS_OPERATOR_OVERLOADING_MYSTRING_H_

#include <cstring>

class MyString {

  friend std::ostream &operator<<(std::ostream &os, const MyString &rhs){
    os << rhs.str;
    return os;
  };

  friend std::istream &operator>>(std::istream &in, MyString &rhs){
    char *buff = new char[1000];
    in >> *buff;
    rhs = MyString{buff};
    delete [] buff;
    return in;
  };

  friend bool operator==(const MyString &lhs, const MyString &rhs){
    return (std::strcmp(lhs.str, rhs.str) == 0);
  };

  friend bool operator!=(const MyString &lhs, const MyString &rhs){
    return std::strcmp(lhs.str, rhs.str) != 0;
  }

 private:

  char *str;

 public:

  MyString &operator=(const MyString &rhs) {
    std::cout << "Copy assignment" << std::endl;

    if (this == &rhs) {
      return *this;
    }

    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);

    return *this;
  }

  MyString &operator=(MyString &&rhs) {
    std::cout << "Move operator" << std::endl;

    if (this == &rhs) {
      return *this;
    }

    delete [] this->str;
    str = rhs.str;
    rhs.str = nullptr;

    return *this;
  };

  MyString operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);

    for (size_t i=0; i < std::strlen(buff); i++) {
      buff[i] = std::tolower(buff[i]);
    }

    MyString temp{buff};
    delete[] buff;
    return temp;
  };

  MyString operator+(const MyString &rhs) const {
    size_t buff_size = (std::strlen(str) + std::strlen(rhs.str) + 1);
    char *buff = new char[buff_size];

    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);

    MyString temp{buff};
    delete [] buff;
    return temp;
  }

  MyString &operator+=(const MyString &rhs) {
    *this = *this + rhs;
    return *this;
  }

  MyString operator*(int n) {
    size_t buff_size = (std::strlen(str) * n) + 1;
    char *buff = new char[buff_size];
    std::strcpy(buff, str);

    for (int i = 0; i < n - 1; i++) {
      std::strcat(buff, str);
    }

    MyString temp{buff};
    delete [] buff;
    return temp;
  }

  MyString &operator*=(int n) {
    *this = *this * n;
    return *this;
  }

  bool operator<(const MyString &rhs) const {
    return ((std::strcmp(this->str, rhs.str)) < 0);
  }

  bool operator>(const MyString &rhs) const {
    return ((std::strcmp(this->str, rhs.str)) > 0);
  }

  MyString() : str{nullptr} {
    str = new char[1];
    *str = '\0';
  };

  MyString(const char *s) : str{nullptr} {
    if (s == nullptr) {
      str = new char[1];
      *str = '\0';
    } else {
      str = new char[std::strlen(s) + 1];
      std::strcpy(str, s);
    }
  };

  MyString(const MyString &source) : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
  };

  ~MyString() {
    delete[] str;
  };

  void display() const {
    std::cout << str << ": length " << get_length() << std::endl;
  };

  size_t get_length() const {
    return std::strlen(str);
  };

  const char *get_str() const {
    return str;
  };

};

#endif