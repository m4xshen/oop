// #ifdef DOUBLE_H
// #define DOUBLE_H

class Double {
private:
  double num;
  double Round();
  double Ceil();
  double Floor();

public:
  Double(double);
  void showResult();
};

// #endif
