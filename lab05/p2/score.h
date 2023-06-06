#pragma once

#include <iostream>
#include <string>

class Score {
 private:
  std::string name;
  double math, science, english;
  double average;

  class Weight {
   private:
     double weighted_avg;
     double math_weight, science_weight, english_weight;
     Score &score;

   public:
     Weight(Score &x);
     void set_weight();
     void weight_avg();
  };

 public:
  Weight w;
  Score();
  void set_score();
  void avg();
  void Change();
};
