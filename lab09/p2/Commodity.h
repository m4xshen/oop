#pragma once
#include <string>

class Commodity {
 public:
  Commodity(std::string name, int price);
  virtual ~Commodity();
  virtual void cal_score() = 0;
  virtual void show_spec() = 0;

  std::string name;
  double* score;
  int* price;

 private:
};
