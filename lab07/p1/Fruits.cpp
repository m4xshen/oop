#include "Fruits.h"
#include "Stocks.h"

Fruits::Fruits(int t, int m, int d) : Stocks(t) {
  expired_month = new int;
  expired_date = new int;
  *expired_month = m;
  *expired_date = d;
}


void Fruits::operator=(const Stocks &s) {
  *expired_month = 0;
  *expired_date = 0;
  Stocks::operator=(s);
}

void Fruits::Display() {
  Stocks::Display();
  if (*expired_month != 0) {
    std::cout << "Expired at " << *expired_month << "/" <<
      *expired_date << "\n";
  } else {
    std::cout << "No Expiration Date\n";
  }
}

Fruits::~Fruits() {
  delete expired_month;
  delete expired_date;
}
