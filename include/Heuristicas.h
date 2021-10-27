/**
 * University of La Laguna
 * Subject: Artificial Intelligence
 * Practice # 1: Search.
 * @author Marco Antonio Cabrera Hernández
 * @author Jose Antonio Trujillo Mendoza
 * @author Mario Hernández García
 * @class Taxi
 * @brief Creates a Taxi object to walk the path
 *
 *
 * @date
*/
#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "Board.h"

#include <cmath>

class Heuristic {
  public:
    Heuristic(void) = default;

    virtual int operator()(const Board&, const Board&) = 0;
};



class Euclidea : public Heuristic {
  public:
    Euclidea(void) = default;

    int operator()(const Board&, const Board&);
};



class Manhattan : public Heuristic {
  public:
    Manhattan(void) = default;

    int operator()(const Board&, const Board&);
};

#endif // F_HEURISTICAS_H