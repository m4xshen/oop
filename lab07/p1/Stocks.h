#ifndef STOCKS_H
#define STOCKS_H
#include <iostream>
#include <string>
class Stocks {
   private:
    int *type;         // number of stock types
    std::string *itemList;  // store all stock name

   public:
    /* any member functions if necessary */
    Stocks(int);
    void operator=(const Stocks &);
    ~Stocks();
    void Initialize();
    void Display();
    int getType() const;
};

#endif
