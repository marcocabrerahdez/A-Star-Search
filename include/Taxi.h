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
#include <vector>
#include <fstream>
#include <cmath>
#include <ctime>

enum direction {NORTH, EAST, SOUTH, WEST};

class Taxi {
  public:
    Taxi(const int& x, const int& y);
    
    int getX_coord() const;
    int getY_coord() const;
    // Prints the taxi in the board
    void printTaxi();
    void printTaxi(std::ofstream& fout);
  private:
    int xCoord;
    int yCoord;
    // Specifies current direction of the taxi
    int direction_;


    clock_t time_;
};

#endif // _TAXI_H