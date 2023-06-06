#include <iostream>
#include "Array.h"

int main(void) {
  int length;
  std::cout << "please enter the inital length: ";
  std::cin >> length;
  std::cout << "please enter " << length << " integer numbers: ";

  int *buffer;
  Array::Arr array;

  Array::initilize(array, buffer, 0);
  for(int i = 0; i < length; i++) {
    Array::add_num(array);
  }

  Array::showArray(array);

  int tmp = Array::count_n(array);
  std::cout << "The counting number appears " << tmp
    << " times in the num_arr\n";

  std::cout << "please enter a new number: ";
  Array::add_num(array);
  Array::showArray(array);

  tmp = Array::count_n(array);
  std::cout << "The counting number appears " << tmp
    << " times in the num_arr\n";

  std::cout << "please enter a new number: ";
  Array::add_num(array);
  Array::showArray(array);

  tmp = Array::count_n(array);
  std::cout << "The counting number appears " << tmp
    << " times in the num_arr\n";

  return 0;
}
