#pragma once

class Complex {
 public:
   Complex();
   Complex(double, double);
   void Print();
   const Complex operator+(const Complex &);
   const Complex operator-(const Complex &);
   const Complex operator*(const Complex &);
   void operator>>(const Complex &);

 private:
   double real;
   double imag;
};
