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
#ifndef _BOARD_H_
#define _BOARD_H_

#include "Colors.h"
#include "Taxi.h"

#include <cassert>
#include <vector>

enum State {FREE, STEPPED, OBSTACLE, INITIAL, END};

class Board {
  public:
    Board(const int& rows, const int& cols);

    int getRows(void) const;
    int getCols(void) const;
    int getCell(const int& x, const int& y);

    void setRows(const int& rows);
    void setCols(const int& cols);
    void setBoard(const int& rows, const int& cols);

    void changeState(const int& x, const int& y, const int& state);
    bool createObstacle(const int& x, const int& y);
    void createRandomObstacle(int& obstacles);

    int readCoordFile(std::ifstream& coord_file);

    void printCell(const int& x, const int& y);
    void printCell(const int& x, const int& y, std::ofstream& fout);
    void printBoard(Taxi taxi);
    void printBoard(Taxi taxi, std::ofstream& fout);
  private:
    int rows_;
    int cols_;

    std::vector<std::vector<int>> board_;
};

#endif // _BOARD_H_