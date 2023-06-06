#include "Phone.h"

Phone::Phone(int in_rate, int out_rate, int length, int width)
  : Electronics(length, width),
    in_rate(in_rate),
    out_rate(out_rate),
    current_power(0) {}

void Phone::poweron() {
  if (current_power > 0) {
    set_usage(true);
  }
}

void Phone::run() {
  if (get_charging()) {
    current_power += in_rate;
  }
  if (get_usage()) {
    current_power -= out_rate;
  }

  if (current_power > 100) {
    current_power = 100;
  } else if (current_power < 0) {
    current_power = 0;
  }

  std::cout << "Phone: (";
  if (!get_charging()) {
    std::cout << "not ";
  }
  std::cout << "charging) " << current_power << "%\n ";

  for (int i = 0; i < width; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
  for (int i = 0; i < length-2; i++) {
    std::cout << "|";
    for (int j = 0; j < width; j++) {
      std::cout << (get_usage() && current_power>0 ? "*" : " ");
    }
    std::cout << "|\n";
  }
  std::cout << " ";
  for (int i = 0; i < width; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
}
