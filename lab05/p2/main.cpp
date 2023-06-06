#include "score.h"
#include <iostream>

void PrintMenu() {
  std::cout << "input 1~4 to select function:\n";
  std::cout << "1.Set score\n";
  std::cout << "2.Set weight\n";
  std::cout << "3.Change score\n";
  std::cout << "4.Show average\n";
  std::cout << "5.Show weight average\n";
}

int main(void) {
  Score score;
  int op;

  while (true) {
    PrintMenu();
    std::cin >> op;
    if (op == 1) {
      score.set_score();
    } else if (op == 2) {
      score.w.set_weight();
    } else if (op == 3) {
      score.Change();
    } else if (op == 4) {
      score.avg();
    } else if (op == 5) {
      score.w.weight_avg();
    }
  }

  return 0;
}
