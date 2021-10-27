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
#ifndef _TAXI_H
#define _TAXI_H

#include "Colors.h"

#include <iostream>
#include <fstream>

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
    // Prints the taxi in the board
    void printTaxi();
    void printTaxi(std::ofstream& fout);
  private:
    // Specifies current direction of the taxi
    int direction_;
    // Specifies the current position of the taxi
    Position position_;
};

#endif // _TAXI_H