/**
 * University of La Laguna
 * Subject: Artificial Intelligence
 * Practice # 1: Search.
 * @author Marco Antonio Cabrera Hernández
 * @author Jose Antonio Trujillo Mendoza
 * @author Mario Hernández García
 * @class Heuristic 
 * @brief Contents the heuristic function that will be used to calculate the path
 *
 * @date 02/11/2021
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



class d_euclidea : public Heuristic {
public:
    d_euclidea(){} = default;
    int operator()(const Cell&, const Cell&);
};



class d_manhattan : public Heuristic {
public:
    d_manhattan() = default;
    int operator()(const Cell&, const Cell&);
};

#endif // F_HEURISTICAS_H