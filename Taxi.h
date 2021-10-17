/** 
 * Universidad de La Laguna
 * Asignatura: Inteligencia Artificial
 * Practica nº1: Búsqueda.
 * @author Marco Cabrera Hernández
 * @author Jose Antonio Trujillo Mendoza
 * @author Mario Hernández García
 * @class Taxi
 * @brief Creates a Taxi object to walk the path
 *  
 * 
 * @date 
 */
#ifndef _TAXI_H
#define _TAXI_H

#include <iostream>
#include <fstream>

#include "Colors.h"

enum direction {NORTH, EAST, SOUTH, WEST};

struct Position {
  int xCoord;
  int yCoord;
};

class Taxi {
  public:
    Taxi(const int& x, const int& y);
    int getX_coord();
    int getY_coord();

    void printTaxi();
    void printTaxi(std::ofstream& fout);
  private:
    int direction_;
    Position position_;
};



#endif // _TAXI_H