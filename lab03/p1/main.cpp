#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

struct Point {
  double x;
  double y;
};

struct Line {
  Point p1;
  Point p2;
};

class LineGp {
public:
  LineGp();
  Line lines[3];
  std::vector<Point> intersectP;

  void set_lines();
  void printLines();
  void computeArea();

private:
  void set_L(int, Line);
  void intersect(Line, Line);
  void intersect_lines();
};

LineGp::LineGp() {}

void LineGp::set_lines() {
  intersectP.clear();

  Line line;
  for(int i = 0; i < 3; i++) {
    std::cout << "L" << i << ":\n";
    std::cout << "Point 1: ";
    std::cin >> line.p1.x >> line.p1.y;
    std::cout << "Point 2: ";
    std::cin >> line.p2.x >> line.p2.y;

    if(line.p2.x<line.p1.x || (line.p2.x==line.p1.x && line.p2.y < line.p1.y)) {
      std::swap(line.p1, line.p2);
    }
    set_L(i, line);
  }
}

void LineGp::printLines() {
  std::cout << "////LINES////\n";
  for(int i = 0; i < 3; i++) {
    std::cout << "L" << i << ": "
      << "(" << lines[i].p1.x << "," << lines[i].p1.y << ") "
      << "(" << lines[i].p2.x << "," << lines[i].p2.y << ")\n";
  }
  std::cout << "////LINES////\n\n";

  intersect_lines();
}

void LineGp::set_L(int i, Line line) {
  lines[i] = line;
}

void LineGp::intersect(Line l1, Line l2) {
  double a1 = l1.p2.y - l1.p1.y;
  double b1 = l1.p1.x - l1.p2.x;
  double c1 = a1*l1.p1.x + b1*l1.p1.y;

  if(b1 < 0) std::cout << a1 << "x - " << -b1 << "y = " << c1 << "\n";
  else std::cout << a1 << "x + " << b1 << "y = " << c1 << "\n";

  double a2 = l2.p2.y - l2.p1.y;
  double b2 = l2.p1.x - l2.p2.x;
  double c2 = a2*l2.p1.x + b2*l2.p1.y;

  if(b2 < 0) std::cout << a2 << "x - " << -b2 << "y = " << c2 << "\n";
  else std::cout << a2 << "x + " << b2 << "y = " << c2 << "\n";

  double determinant = a1*b2 - a2*b1;

  if(determinant != 0) {
    double x = (b2*c1 - b1*c2)/determinant;
    double y = (a1*c2 - a2*c1)/determinant;

    if(x>=std::min(l1.p1.x, l1.p2.x) && x<=std::max(l1.p1.x, l1.p2.x) &&
       x>=std::min(l2.p1.x, l2.p2.x) && x<=std::max(l2.p1.x, l2.p2.x) &&
       y>=std::min(l1.p1.y, l1.p2.y) && y<=std::max(l1.p1.y, l1.p2.y) &&
       y>=std::min(l2.p1.y, l2.p2.y) && y<=std::max(l2.p1.y, l2.p2.y)) {
      std::cout << "Intersect at (" << x << "," << y << ")\n";

      Point point;
      point.x = x;
      point.y = y;
      intersectP.push_back(point);
    }
    else {
      std::cout << "Intersect point isn't in range!\n";
    }
    return;
  }
  std::cout << "Two lines are parallel!\n";
}

void LineGp::intersect_lines() {
  for(int i = 0; i < 3; i++) {
    for(int j = i+1; j < 3; j++) {
      std::cout << "L" << i << ", L" << j << "\n";
      intersect(lines[i], lines[j]);
    }
  }
}

double dis(Point p1, Point p2) {
  return std::sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void LineGp::computeArea() {
  std::cout << "\n";
  if(intersectP.size() == 3) {
    double a = dis(intersectP[0], intersectP[1]);
    double b = dis(intersectP[0], intersectP[2]);
    double c = dis(intersectP[1], intersectP[2]);

    double s = (a+b+c) / 2;
    double area = std::sqrt(s * (s-a) * (s-b) * (s-c));
    if(area > 0) {
      std::cout << "Area is: " << area << "\n\n";
      return;
    }
  }
  std::cout << "No Triangle\n\n";
}

int main(void) {
  LineGp lineGp;

  while(1) {
    lineGp.set_lines();
    lineGp.printLines();
    lineGp.computeArea();
  }

  return 0;
}
