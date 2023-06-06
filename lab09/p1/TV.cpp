#include "TV.h"
#include "Electronics.h"

TV::TV(int length, int width): Electronics(length, width) {}

void TV::run() {
  std::cout << "TV: (";
  if (!get_charging()) {
    std::cout << "not ";
  }
  std::cout << "charging)\n ";
  for (int i = 0; i < width; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
  for (int i = 0; i < length-2; i++) {
    std::cout << "|";
    for (int j = 0; j < width; j++) {
      std::cout << (get_usage() && get_charging() ? "*" : " ");
    }
    std::cout << "|\n";
  }
  std::cout << " ";
  for (int i = 0; i < width; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
}

void TV::poweron() {
  if (get_charging()) {
    set_usage(true);
  }
}
