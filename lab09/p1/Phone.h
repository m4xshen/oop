#pragma once
#include <iostream>
#include "Electronics.h"

class Phone : public Electronics {
 public:
  Phone(int, int, int, int);
  ~Phone();
  void poweron() override;
  void run() override;
 
 private:
  int current_power;
  int in_rate;
  int out_rate;
};
