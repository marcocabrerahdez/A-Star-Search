#include "Heuristicas.h"

int Euclidea::operator()(const Board& i, const Board& f){
  return static_cast<int>(sqrt(pow((i.getRows() - f.getRows()),2) + pow((i.getCols() - f.getCols()), 2)));
}



int Manhattan::operator()(const Board& i, const Board& f){
  return static_cast<int>(fabs(static_cast<double>(i.getRows() - f.getRows())) + fabs(static_cast<double>(i.getCols() - f.getCols())));
}