#include "Shape.h"
#include <algorithm>
#include <cmath>

Shape::Shape(int L, int pos_x, int pos_y, int canvas_size = 20)
  : L(L), pos_x(pos_x), pos_y(pos_y), canvas_size(canvas_size) {}

void Shape::appendPoints(int x, int y) {
  points.push_back(Point{x, y});
}

int Shape::getL() {
  return L;
}

int Shape::getX() {
  return pos_x;
}

int Shape::getY() {
  return pos_y;
}

void Shape::draw() {
  for (int x = 0; x < canvas_size; x++) {
    if (x == 0 ) std::cout << "|";
    std::cout << x % 10;
    if (x == canvas_size-1) std::cout << "|";
  }
  std::cout << "\n";

  for (int y = canvas_size-1; y >= 0; y--) {
    std::cout << y % 10;
    for (int x = 0; x < canvas_size; x++) {
      bool found = false;
      for (Point p : points) {
        if (p.x == x && p.y == y) {
          found = true;
          break;
        }
      }

      std::cout << (found ? "*" : " ");
    }
    std::cout << y % 10 << "\n";
  }

  for (int x = 0; x < canvas_size; x++) {
    if (x == 0 ) std::cout << "|";
    std::cout << x % 10;
    if (x == canvas_size-1) std::cout << "|";
  }
}

#include "Circle.h"

Circle::Circle(int L, int pos_x, int pos_y, int canvas_size)
  : Shape(L, pos_x, pos_y, canvas_size) {}

void Circle::ComputeArea() {
  std::cout << "Area: " << getL()*getL()*PI << "\n";
}

void Circle::ComputePerimeter() {
  std::cout << "Perimeter: " << 2*getL()*PI << "\n";
}

void Circle::ComputePoints() {
  appendPoints(getX(), getY()-getL());
  appendPoints(getX(), getY()+getL());

  for (int y = getY()-getL()+1; y < getY()+getL(); y++) {
    appendPoints(getX() + round(sqrt(getL()*getL() - (y-getY())*(y-getY()))), y);
    appendPoints(getX() - round(sqrt(getL()*getL() - (y-getY())*(y-getY()))), y);
  }
}

#include "Rect.h"

Rect::Rect(int L, int W, int pos_x, int pos_y, int canvas_size)
  : Shape(L, pos_x, pos_y, canvas_size), W(W) {}

void Rect::ComputeArea() {
  std::cout << "Area: " << getL()*W << "\n";
}

void Rect::ComputePerimeter() {
  std::cout << "Perimeter: " << 2*(getL()+W) << "\n";
}

void Rect::ComputePoints() {
  for (int x = getX()-(getL()-1)/2; x <= getX()+(getL()-1)/2; x++) {
    appendPoints(x, getY()-(W-1)/2);
    appendPoints(x, getY()+(W-1)/2);
  }

  for (int y = getY()-(W-1)/2; y <= getY()+(W-1)/2; y++) {
    appendPoints(getX()-(getL()-1)/2, y);
    appendPoints(getX()+(getL()-1)/2, y);
  }
}
