#pragma once
#include <iostream>
#include "Commodity.h"

class Food : public Commodity {
 public:
  Food(std::string, int, int, int, int);
  ~Food();
  void cal_score() override;
  void show_spec() override;

 private:
  int* car_value;
  int* pro_value;
  int* fat_value;
};
