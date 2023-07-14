#include <iostream>

using namespace std;

int* apply_all(const  int *array1, int array1_size, const  int *array2, int array2_size);
void print(const int *const array, size_t size);

int main () {

  const size_t array1_size{5};
  const size_t array2_size{3};

  int array_1[]{1, 2, 3, 4, 5};
  int array_2[]{10, 20, 30};

  cout << "Array 1: ";
  print(array_1, 5);

  cout << "Array 2: ";
  print(array_2, 3);

  int* result = apply_all(array_1, array1_size, array_2, array2_size);
  cout << "Result: ";
  print(result, array1_size * array2_size);

  delete [] result;

  return 0;

}

int* apply_all(const int *array1, int array1_size, const int *array2, int array2_size) {

  int *new_array{nullptr};
  int size = array1_size * array2_size;
  new_array = new int[size];

  int index{0};
  for (size_t i{0}; i < array1_size; i++) {
    for (size_t j{0}; j < array2_size; j++) {
      *(new_array + index) =  *(array1 + i) * *(array2 + j);
      index++;
    }
  }

  return new_array;

}

void print(const int *const array, size_t size){

  cout << "[ ";
  for (int i = 0; i < size; i++){
    cout << array[i] << " ";
  }
  cout << "]";
  cout << endl;

}