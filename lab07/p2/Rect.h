#ifndef RECT_H
#define RECT_H

#include "Shape.h"

class Rect : public Shape {
   private:
    int W;

   public:
    /* any member functions if necessary */
    Rect(int, int, int, int, int canvas_size = 20);
    void ComputeArea();
    void ComputePerimeter();
    void ComputePoints();
};

#endif
