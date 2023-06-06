#pragma once
#include "Commodity.h"

class Healthy : public Commodity {
 public:
  Healthy(std::string, int, int, std::string *, int *);
  ~Healthy();
  void cal_score() override;
  void show_spec() override;

 private:
  std::string *name_arr;
  int* value_arr;
  int arr_length;
};
