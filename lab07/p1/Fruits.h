#ifndef FRUITS_H
#define FRUITS_H
#include "Stocks.h"

class Fruits : public Stocks {
   private:
    int *expired_month;
    int *expired_date;

   public:
    Fruits(int, int, int);
    Fruits(Stocks);
    void operator=(const Stocks &);
    ~Fruits();
    void Display();
    /* any member functions if necessary */
};

#endif
