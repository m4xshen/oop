#ifndef SHAPE_H
#define SHAPE_H

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

class Shape {
   private:
    int L;
    int pos_x;
    int pos_y;
    int canvas_size;
    vector<Point> points;  // all plotting points

   public:
    /* any member functions if necessary */
    Shape(int, int, int, int);
    void appendPoints(int x, int y);
    void draw();
    int getL();
    int getX();
    int getY();
};

#endif
