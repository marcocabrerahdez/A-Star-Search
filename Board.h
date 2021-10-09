/** 
 * Universidad de La Laguna
 * Asignatura: Inteligencia Artificial
 * Practica nº1: Búsqueda.
 * @author Marco Cabrera Hernández
 * @author Jose Antonio Trujillo Mendoza
 * @author 
 * @class Taxi
 * @brief Creates a Board object to show the path
 *  
 * 
 * @date 
 */
#ifndef _BOARD_
#define _BOARD_

#include "Taxi.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

enum State {FREE, STEPPED, OBSTACLE, INITIAL, END};

class Board {
  public:
    Board(const int& rows, const int& cols);

    int getRows();
    int getCols();
    int getCell(const int& x, const int& y);

    void setRows(const int& rows);
    void setCols(const int& cols);
    void setBoard(const int& rows, const int& cols);

    void changeState(const int& x, const int& y, const int& state);
    bool createObstacle(const int& x, const int& y);
    void createRandomObstacle(int& KObstacles);

    int readCoordFile(std::ifstream& coord_file);

    void printCell(const int& x, const int& y);
    void printBoard(std::ostream& os = std::cout);

  private:
    int rows_;
    int cols_;

    std::vector<std::vector<int> > board_;
};

#endif // _BOARD_