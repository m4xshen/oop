#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#define PI 3.14

class Circle : public Shape {
   private:
   public:
    /* any member functions if necessary */
     Circle(int, int, int, int canvas_size = 20);
     void ComputeArea();
     void ComputePerimeter();
     void ComputePoints();
};
#endif
