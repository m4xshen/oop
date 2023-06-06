#include "Food.h"

Food::Food(std::string name, int price, int car, int pro, int fat)
  : Commodity(name, price) {
  car_value = new int(car);
  pro_value = new int(pro);
  fat_value = new int(fat);
}

Food::~Food() {
  delete car_value;
  delete pro_value;
  delete fat_value;
}

void Food::cal_score() {
  score = new double((double)*pro_value / *price);
}

void Food::show_spec() {
  cal_score();
  std::cout << "=======================================\n";
  std::cout << "name: " << name << "\n";
  std::cout << "price: " << *price << "\n";
  std::cout << "car: " << *car_value << "\n";
  std::cout << "pro: " << *pro_value << "\n";
  std::cout << "fat: " << *fat_value << "\n";
  std::cout << "score: " << *score << "\n";
}
