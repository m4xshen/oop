#include "Commodity.h"
#include "Food.h"
#include "Healthy.h"
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
  std::ifstream fin("2.txt");
  std::vector<Commodity *> vc;

  std::string type;
  while (fin >> type) {
    std::string name;
    int price;
    fin >> name >> price;
    Commodity *pt;
    if (type == "H") {
      int arr_length;
      fin >> arr_length;

      std::string name_arr[arr_length];
      int value_arr[arr_length];

      for (int i = 0; i < arr_length; i++) {
        fin >> name_arr[i] >> value_arr[i];
      }
      pt = new Healthy(name, price, arr_length, name_arr, value_arr);
    } else {
      int car, pro, fat;
      fin >> car >> pro >> fat;
      pt = new Food(name, price, car, pro, fat);
    }
    vc.push_back(pt);
  }

  std::sort(vc.begin(), vc.end(),
    [](Commodity *ca, Commodity *cb) {
      return (ca->name).compare(cb->name) < 0;
    });

  for (Commodity *c : vc) {
    c->show_spec();
    delete c;
  }
  std::cout << "=======================================\n";

  return 0;
}
