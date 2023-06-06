#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

int main(int argc, char **argv) {
  std::ifstream file(argv[1]);
  int file_size;

  file.seekg(0, file.end);
  file_size = file.tellg() / sizeof(int);
  file.seekg(0, file.beg);

  std::vector<int> v;
  int num;
  for (int i = 0; i < file_size; i++) {
    file.read((char*)&num, sizeof(int));
    std::cout << num << " ";
    v.push_back(num);
  }
  std::cout << "\n";

  std::make_heap(v.begin(), v.end(), [](int a, int b) { return a > b; });

  int n = 1;
  int l = n;
  int hei = 1;
  for (int num : v) {
    if (l-- == 0) {
      n *= 2;
      l = n;
      hei++;
    }
  }

  std::cout << "\n";
  n = 1;
  l = n;
  int i = 0;
  for (int num : v) {
    if (i == 0) {
      std::cout << std::setw(std::pow(2, hei-i)*3/4);
    } else {
      std::cout << std::setw(std::pow(2, hei-i));
    }
    std::cout << num;
    std::cout << " ";

    if (--l == 0) {
      std::cout << "\n";
      n *= 2;
      l = n;
      i++;
    }
  }

  std::cout << "\n\n";
  std::sort_heap(v.begin(), v.end(), [](int a, int b) { return a > b; });
  for (auto it = v.rbegin(); it != v.rend(); it++)
    std::cout << *it << " ";
  std::cout << "\n";

  return 0;
}
