#include "Healthy.h"
#include <string>
#include <iostream>

Healthy::Healthy(std::string name, int price, int arr_length, std::string *name_arr, int *value_arr)
  : Commodity(name, price), arr_length(arr_length) {
  this->name_arr = new std::string[arr_length];
  this->value_arr = new int[arr_length];
  for (int i = 0; i < arr_length; i++) {
    this->name_arr[i] = name_arr[i];
    this->value_arr[i] = value_arr[i];
  }
}

Healthy::~Healthy() {
  delete[] name_arr;
  delete[] value_arr;
}

void Healthy::cal_score() {
  double sum = 0;
  for (int i = 0; i < arr_length; i++) {
    sum += double(value_arr[i]) / *price;
  }
  score = new double(sum);
}

void Healthy::show_spec() {
  cal_score();
  std::cout << "=======================================\n";
  std::cout << "name: " << name << "\n";
  std::cout << "price: " << *price << "\n";
  for (int i = 0; i < arr_length; i++) {
    std::cout << name_arr[i] << ": " << value_arr[i] << "\n";
  }
  std::cout << "score: " << *score << "\n";
}
