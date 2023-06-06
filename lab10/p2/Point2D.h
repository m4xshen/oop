#pragma once

#include <ostream>

class Point2D {
 public:
  Point2D();
  Point2D(int, int);
  void operator = (const Point2D &);
  void set_x(int);
  void set_y(int);
  int get_x() const;
  int get_y() const;
  friend std::ostream &operator<<(std::ostream &os, const Point2D);

 private:
  int x;
  int y;
};
