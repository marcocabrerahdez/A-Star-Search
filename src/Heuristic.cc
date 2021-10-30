#include "../include/Heuristic.h"

Heuristic::~Heuristic(){}

/**
 * @brief The Euclidean distance is the length of a line segment between the two points
 */
int d_euclidea::operator()(const Cell& i, const Cell& f){
    return static_cast<int>(sqrt(pow((i.get_xCoord() - f.get_xCoord()),2) + pow((i.get_yCoord() - f.get_yCoord()), 2)));
}

/**
 * @brief The Manhattan distance is the distance a car would drive in a city
    where the buildings are laid out in square blocks and the straight streets intersect at right angles.
 */
int d_manhattan::operator()(const Cell& i, const Cell& f){
    return static_cast<int>(fabs(static_cast<double>(i.get_xCoord() - f.get_xCoord())) + fabs(static_cast<double>(i.get_yCoord() - f.get_yCoord())));
}