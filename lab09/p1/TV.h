#pragma once
#include <iostream>
#include "Electronics.h"

class TV : public Electronics {
 public:
  TV(int, int);
  void run() override;
  void poweron() override;
};
