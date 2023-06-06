#include <iostream>
#include "Array.h"

int main(void) {
  int length;
  std::cout << "please enter the inital length: ";
  std::cin >> length;
  std::cout << "please enter " << length << " integer numbers: ";

  int buffer[1];
  Array array(buffer, 0);

  for(int i = 0; i < length; i++) {
    array.add_num();
  }

  array.showArray();

  int tmp = array.count_n();
  std::cout << "The counting number appears " << tmp
    << " times in the num_arr\n";

  std::cout << "please enter a new number: ";
  array.add_num();
  array.showArray();

  tmp = array.count_n();
  std::cout << "The counting number appears " << tmp
    << " times in the num_arr\n";

  std::cout << "please enter a new number: ";
  array.add_num();
  array.showArray();

  tmp = array.count_n();
  std::cout << "The counting number appears " << tmp
    << " times in the num_arr\n";

  return 0;
}
