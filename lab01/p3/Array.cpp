#include <iostream>
#include "Array.h"

namespace Array {
void initilize(Arr &A, int* arr, int length) {
  A.num_arr = arr;
  A.length = length;
}

void add_num(Arr &A) {
  int *new_num_arr = new int[A.length+1]();

  for(int i = 0; i < A.length; i++) {
    new_num_arr[i] = A.num_arr[i];
  }
  int num;
  std::cin >> num;
  new_num_arr[A.length++] = num;

  A.num_arr = new_num_arr;
}

void showArray(Arr &A) {
  std::cout << "The number in num_arr is";
  for(int i = 0; i < A.length; i++) {
    std::cout << " " << A.num_arr[i];
  }
  std::cout << "\n";
}

int count_n(Arr &A) {
  int num;
  std::cout << "please enter a counting number: ";
  std::cin >> num;

  int ans = 0;
  for(int i = 0; i < A.length; i++) {
    if(A.num_arr[i] == num) ans++;
  }

  return ans;
}
}
