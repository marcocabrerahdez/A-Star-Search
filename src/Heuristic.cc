#include "../include/Heuristic.h"

int d_euclidea::operator()(const Cell& i, const Cell& f){
    return static_cast<int>(sqrt(pow((i.getX() - f.getX()),2) + pow((i.getY() - f.getY()), 2)));
}


int d_manhattan::operator()(const Cell& i, const Cell& f){
    return static_cast<int>(fabs(static_cast<double>(i.getX() - f.getX())) + fabs(static_cast<double>(i.getY() - f.getY())));
}