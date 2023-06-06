#include <iostream>
#include "Array.h"

Array::Array(int *num_arr, int length) : num_arr(num_arr), length(length) {}

Array::~Array() {
  delete num_arr;
}

void Array::add_num() {
  int *new_num_arr = new int[length+1]();

  for(int i = 0; i < length; i++) {
    new_num_arr[i] = num_arr[i];
  }
  int num;
  std::cin >> num;
  new_num_arr[length++] = num;

  num_arr = new_num_arr;
}

void Array::showArray() {
  std::cout << "The number in num_arr is";
  for(int i = 0; i < length; i++) {
    std::cout << " " << num_arr[i];
  }
  std::cout << "\n";
}

int Array::count_n() {
  int num;
  std::cout << "please enter a counting number: ";
  std::cin >> num;

  int ans = 0;
  for(int i = 0; i < length; i++) {
    if(num_arr[i] == num) ans++;
  }

  return ans;
}
