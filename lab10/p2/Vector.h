#pragma once

#include "Point2D.h"
#include <iostream>

template <typename T>
class Vector {
 public:
  Vector(int len, T init) : len(len) {
    vec = new T[len];
    for (int i = 0; i < len; i++) {
      vec[i] = init;
    }
  }

  Vector(int len, T* vec) : len(len) {
    this->vec = new T[len];
    for (int i = 0; i < len; i++) {
      this->vec[i] = vec[i];
    }
  }

  void display() {
    for (int i = 0; i < len; i++) {
      std::cout << vec[i] << " ";
    }
    std::cout << "\n";
  }

  void operator+=(Vector<T> vt) {
    for (int i = 0; i < len; i++) {
      this->vec[i] += vt.vec[i];
    }
  }

  template<typename S>
  friend S dot(const Vector<S> &, const Vector<S> &);

  template<typename S>
  friend void rand1D(const Vector<S> &, int);

 private:
  int len;
  T* vec;
};

template<typename S>
S dot(const Vector<S> &vs1, const Vector<S> &vs2) {
  S ans = 0;
  for (int i = 0; i < vs1.len; i++) {
    ans += vs1.vec[i] * vs2.vec[i];
  }
  return ans;
}

template <>
Point2D dot(const Vector<Point2D> &p1, const Vector<Point2D> &p2) {
  int ans_x = 0;
  int ans_y = 0;
  for (int i = 0; i < p1.len; i++) {
    ans_x += p1.vec[i].get_x();
    ans_y += p1.vec[i].get_y();
  }

  return Point2D(ans_x, ans_y);
}

template<typename S>
void rand1D(const Vector<S> &, int) {}

template <>
void rand1D(const Vector<Point2D> &vs, int len) {
  for (int i = 0; i < len; i++) {
    vs.vec[i].set_x(rand() % 10);
    vs.vec[i].set_y(rand() % 10);
  }
}
