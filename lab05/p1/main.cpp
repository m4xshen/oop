#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <type_traits>
#include "complex.h"

void InputComplex(std::string &inp, double &real, double &imag) {
  int sign = 1;
  int num = 0;

  for (char c : inp) {
    if (c == 'j') {
      if (num == 0) num = 1;
      imag += num * sign;
      num = 0;
    } else if (c=='+' || c=='-') {
      real += num * sign;
      num = 0;

      // update sign
      if (c == '+') {
        sign = 1;
      } else {
        sign = -1;
      }
    } else {
      num += c - '0';
    }
  }
  if (num != 0) real += num * sign;
}

int main(void) {
  std::string inp;
  std::cout << "input complex number: ";
  std::cin >> inp;
  double real = 0;
  double imag = 0;
  InputComplex(inp, real, imag);
  Complex c1(real, imag);
  Complex last_c2;

  std::string last_op;
  bool use_last = false;
  std::string op;
  while (true) {
    if (!use_last) {
      std::cout << "input operator: ";
      std::cin >> op;
    } 

    if (op=="+" || op=="-" || op=="*") {
      if (!use_last) {
        std::cout << "input complex number: ";
        std::cin >> inp;
        real = 0;
        imag = 0;
        InputComplex(inp, real, imag);
      }
      Complex c2(real, imag);

      if (use_last) c2 = last_c2;
      last_c2 = c2;

      Complex ans;
      if (op == "+") {
        ans = c1 + c2;
      } else if (op == "-") {
        ans = c1 - c2;
      } else {
        ans = c1 * c2;
      }
      std::cout << "Complex number is: ";
      ans.Print();
      c1 = ans;
      use_last = false;
    } else if (op == ">>") {
      c1 >> c1;
      std::cout << "Complex number is: ";
      c1.Print();
      use_last = false;
    } else if (op == "=") {
      op = last_op;
      use_last = true;
    }

    last_op = op;
  }

  return 0;
}
