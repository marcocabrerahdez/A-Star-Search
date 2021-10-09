/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 4 Palabras de Fibonacci
 * @author Marco Cabrera Hernández
 * @author 
 * @author 
 * @class Taxi
 * @brief Creates a Taxi object to walk the path
 *  
 * 
 * @date 09/10/2021
 */
#ifndef _TAXI_
#define _TAXI_

enum direction {NORTH, EAST, SOUTH, WEST};

struct Position {
  int xCoord;
  int yCoord;
};

class Taxi {
  public:
    Taxi(const int& x, const int& y);
  private:
    int direction_;
    Position position_;
};

#endif // _TAXI_