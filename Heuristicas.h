#ifndef HEURISTICAS_H
#define HEURISTICAS_H

#include "Board.h"

#include <cmath>

class Heuristicas {
  public:
    Heuristicas(void) = default;

    virtual int operator()(const Board&, const Board&) = 0;
};



class Euclidea : public Heuristicas {
  public:
    Euclidea(void) = default;

    int operator()(const Board&, const Board&);
};



class Manhattan : public Heuristicas {
  public:
    Manhattan(void) = default;

    int operator()(const Board&, const Board&);
};

#endif // F_HEURISTICAS_H