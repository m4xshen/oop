#include "Stocks.h"
#include "Fruits.h"

Stocks::Stocks(int t) {
  type = new int;
  *type = t;
  itemList = new std::string[t];
}

void Stocks::operator=(const Stocks &s) {
  delete type;
  type = new int;
  *type = *(s.type);

  delete[] itemList;
  itemList = new std::string[*type];
  for (int i = 0; i < *type; i++) {
    itemList[i] = s.itemList[i];
  }
}

Stocks::~Stocks() {
  delete type;
  delete[] itemList;
}

void Stocks::Initialize() {
  std::cout << "Initialize\n";
  for (int i = 0; i < *type; i++) {
    std::cout << "Item " << i+1 << ": ";
    std::cin >> itemList[i];
  }
}

void Stocks::Display() {
  std::cout << "Item List: ";
  for (int i = 0; i < *type; i++) {
    std::cout << itemList[i] << " ";
  }
  std::cout << "\n";
}

int Stocks::getType() const {
  return *type;
}
