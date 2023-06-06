#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

class Point2D {
 public:
  Point2D();
  Point2D(int, int);
  void operator=(int);
  friend std::ostream& operator<<(std::ostream&, Point2D);
  bool operator<(Point2D);

 private:
  int x;
  int y;
};

Point2D::Point2D() {}

Point2D::Point2D(int x, int y) : x(y), y(x) {}

void Point2D::operator=(int n) {
  x = rand() % 10;
  y = rand() % 10;
}

std::ostream& operator<<(std::ostream &os, Point2D p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

bool Point2D::operator<(Point2D p) {
  return (this->x == p.x) ? this->y < p.y : this->x < p.x;
}

template<typename T>
T* new1D(int n) {
  T *pt = new T[n];
  return pt;
}

template<typename T>
void rand1D(T *vec, int n) {}

template<>
void rand1D<int>(int *vec, int n) {
  for (int i = 0; i < n; i++) {
    vec[i] = rand() % 10;
  }
}

template<>
void rand1D<double>(double *vec, int n) {
  for (int i = 0; i < n; i++) {
    vec[i] = rand() % 1000 / 100.0;
  }
}

template<>
void rand1D<char>(char *vec, int n) {
  for (int i = 0; i < n; i++) {
    vec[i] = 'A' + rand() % 26;
  }
}

template<>
void rand1D<Point2D>(Point2D *vec, int n) {
  for (int i = 0; i < n; i++) {
    vec[i] = Point2D(rand() % 10, rand() % 10);
  }
}

template<typename T>
void display1D(T* vec, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << "\n";
}

template<>
void display1D<double>(double *vec, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << std::fixed << std::setprecision(2) << vec[i] << " ";
  }
  std::cout << "\n";
}

template<typename T>
void sort1D(T* vec, int n) {
  std::sort(vec, vec + n);
}

template<typename T>
void analysis(int n) {
  T *vec = new1D<T>(n);
  rand1D<T>(vec, n);         
  // for int, 0~9
  // for double, 0.00~9.99, i.e., rand()%1000/100.0
  // for char, A~Z 
  // for Point2D, x: 0~9 y: 0~9
  display1D<T>(vec, n);
  // for double, set the precision with 2
  sort1D<T>(vec, n);
  display1D<T>(vec, n);
}

int main() {
  int n;
  std::cout << "Enter n: ";
  std::cin >> n;

  srand(1);

  analysis<int>(n);
  analysis<double>(n);
  analysis<char>(n);
  analysis<Point2D>(n);

  return 0;
}
