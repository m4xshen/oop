#include "Commodity.h"

Commodity::Commodity(std::string name, int price) : name(name) {
  this->price = new int(price);
}

Commodity::~Commodity() {
  delete score;
  delete price;
}
