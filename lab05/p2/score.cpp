#include "score.h"
#include <cmath>
#include <math.h>

Score::Score() : w(*this) {}

void Score::set_score() {
  std::cout << "name: "; std::cin >> name;
  std::cout << "math score: "; std::cin >> math;
  std::cout << "science score: "; std::cin >> science;
  std::cout << "english score: "; std::cin >> english;
}

void Score::avg() {
  std::cout << "average is: " << (math+science+english) / 3.0 << "\n";
}

void Score::Change() {
  math = std::sqrt(math) * 10;
  science = std::sqrt(science) * 10;
  english = std::sqrt(english) * 10;

  avg();
}

Score::Weight::Weight(Score &x) : score(x) {} 

void Score::Weight::set_weight() {
  std::cout << "math weight: "; std::cin >> math_weight;
  std::cout << "science weight: "; std::cin >> science_weight;
  std::cout << "english weight: "; std::cin >> english_weight;
}

void Score::Weight::weight_avg() {
  std::cout << "Weighted average is: ";
  std::cout << (score.math * math_weight +
      score.science * science_weight +
      score.english * english_weight) << "\n";
}
