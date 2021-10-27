/** 
 * Universidad de La Laguna
 * Asignatura: Inteligencia Artificial
 * Practica nº1: Búsqueda.
 * @author Marco Antonio Cabrera Hernández
 * @author Jose Antonio Trujillo Mendoza
 * @author Mario Hernández García
 * @class Taxi
 * @brief Creates a Taxi object to walk the path
 *  
 * 
 * @date 
 */
#include "../include/Heuristicas.h"

int Euclidea::operator()(const Board& i, const Board& f){
  return static_cast<int>(sqrt(pow((i.getRows() - f.getRows()),2) + pow((i.getCols() - f.getCols()), 2)));
}



int Manhattan::operator()(const Board& i, const Board& f){
  return static_cast<int>(fabs(static_cast<double>(i.getRows() - f.getRows())) + fabs(static_cast<double>(i.getCols() - f.getCols())));
}