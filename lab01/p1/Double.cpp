#include <iostream>
#include <cmath>
#include "Double.h"

Double::Double(double num) : num(num) {}

double Double::Round() {
  return std::round(num);
}

double Double::Ceil() {
  return std::ceil(num);
}

double Double::Floor() {
  return std::floor(num);
}

void Double::showResult() {
  std::cout << "the beginning of the function(showResult)\n";
  std::cout << "Round(" << num << ") = " << Round() << "\n";
  std::cout << "Ceil(" << num << ") = " << Ceil() << "\n";
  std::cout << "Floor(" << num << ") = " << Floor() << "\n";
  std::cout << "the end of the function(showResult)\n";
}
