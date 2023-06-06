#include "Point2D.h"
#include <ostream>

Point2D::Point2D() : x(1), y(1) {}

Point2D::Point2D(int x, int y) : x(x), y(y) {}

void Point2D::operator=(const Point2D &p) {
  x = p.x;
  y = p.y;
}

std::ostream &operator<<(std::ostream &os, const Point2D p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

void Point2D::set_x(int x) {
  this->x = x;
}

void Point2D::set_y(int y) {
  this->y = y;
}

int Point2D::get_x() const {
  return x;
}

int Point2D::get_y() const {
  return y;
}
