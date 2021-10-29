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
#ifndef F_HEURISTICS_H
#define F_HEURISTICS_H

#include "Cell.h"

#include <cmath>


class Heuristic {
  public:
    Heuristic() = default;
    virtual ~Heuristic();

    virtual int operator()(const Cell&, const Cell&) = 0;
};

//-----------------------DISTANCIA EUCLIDEA-------------------------

class d_euclidea : public Heuristic {
public:
    d_euclidea() = default;
    int operator()(const Cell&, const Cell&);
};

//-----------------------DISTANCIA RECTILINEA-----------------------

class d_manhattan : public Heuristic {
public:
    d_manhattan() = default;
    int operator()(const Cell&, const Cell&);
};

#endif // F_HEURISTICAS_H