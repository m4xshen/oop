#include <iostream>
#include "Double.h"

int main(void) {
  double val;
  std::cout << "Please enter a number: ";
  std::cin >> val;

  Double d(val);
  d.showResult();

  return 0;
}
