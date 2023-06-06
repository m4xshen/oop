#include <cmath>
#include <iostream>
#include "complex.h"

#define PI 3.14159265

Complex::Complex() {}

Complex::Complex(double real, double imag)
  : real(real), imag(imag) {}

void Complex::Print() {
  if (real==0 && imag==0) {
    std::cout << 0 << "\n";
    return;
  }

  if (real != 0) std::cout << real;

  if (imag == 0) {
    std::cout << "\n";
    return;
  }

  if (imag == 1) std::cout << "+j";
  else if (imag == -1) std::cout << "-j";
  else if (imag > 0) std::cout << "+" << imag << "j";
  else std::cout << imag << "j";

  std::cout << "\n";
}

const Complex Complex::operator+(const Complex &c) {
  return Complex(real+c.real, imag+c.imag);
}

const Complex Complex::operator-(const Complex &c) {
  return Complex(real-c.real, imag-c.imag);
}

const Complex Complex::operator*(const Complex &c) {
  return Complex(real*c.real - imag*c.imag, real*c.imag + imag*c.real);
}

void Complex::operator>>(const Complex &c) {
  double r = std::sqrt(c.imag*c.imag + c.real*c.real);
  double theta = std::atan(c.imag / c.real) * 180 / PI;;
  std::cout << "Polar form is: ";
  std::cout << r << "(cos" << theta << "+isin" << theta << ")\n"; 
}
