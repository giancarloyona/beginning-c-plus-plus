#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector <int> vector1{};
  vector <int> vector2{};

  vector1.push_back(10);
  vector1.push_back(20);
  cout << "Vector 1: " << endl;
  cout << vector1.at(0) << " " << vector1.at(1) << endl;
  cout << "Vector 1 size: " << vector1.size() << endl;

  vector2.push_back(100);
  vector2.push_back(200);
  cout << "\nVector 2: " << endl;
  cout << vector2.at(0) << " " << vector2.at(1) << endl;
  cout << "Vector 2 size: " << vector2.size() << endl;

  vector <vector<int>> vector_2d{};
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  cout << "\nDisplaying vector_2d data:" << endl;
  cout << vector_2d[0][0] << " " << vector_2d[0][1] << endl;
  cout << vector_2d[1][0] << " " << vector_2d[1][1] << endl;

  cout << "\nChanging vetor1 data" << endl;
  vector1.at(0) = 1000;

  cout << "\nVector 1 new data: " << endl;
  cout << vector1.at(0) << " " << vector1.at(1) << endl;

  cout << "\nDisplaying vector_2d data after change:" << endl;
  cout << vector_2d[0][0] << " " << vector_2d[0][1] << endl;
  cout << vector_2d[1][0] << " " << vector_2d[1][1] << endl;


}