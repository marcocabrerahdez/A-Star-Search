/**
 * University of La Laguna
 * Subject: Artificial Intelligence
 * Practice # 1: Search.
 * @author Marco Antonio Cabrera Hernández
 * @author Jose Antonio Trujillo Mendoza
 * @author Mario Hernández García
 * @class Board
 * @brief Creates a Board object to create a 2 dimension board
 *
 *
 * @date
*/
#ifndef _BOARD_H_
#define _BOARD_H_

#include "Colors.h"
#include "Position.h"


#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <vector>

enum State {FREE, STEPPED, OBSTACLE, INITIAL, END};

class Board {
  public:
    Board(const int& rows, const int& cols);
    
    // Getters
    int getRows(void) const;
    int getCols(void) const;
    int getCell(const int& x, const int& y);
    // Reads the coordinates given from a file
    int readCoordFile(std::ifstream& coord_file);
    Position getInitial() const;
    Position getGoal() const;
    // Setters
    void setRows(const int& rows);
    void setCols(const int& cols);
    void setInitial(const int& rows, const int& cols);
    void setGoal(const int& rows, const int& cols);
    void setBoard(const int& rows, const int& cols);
    // Changes the state of a specific cell of the board
    void changeState(const int& x, const int& y, const int& state);
    // Creates a random obstacles on the board
    void createRandomObstacle(int& obstacles);
    // Print a specific cell of the board
    void printCell(const int& x, const int& y);
    // Print a specific cell of the board in a file
    void printCell(const int& x, const int& y, std::ofstream& fout);
    // Checks if the obstacle option is on
    bool createObstacle(const int& x, const int& y);
  private:
    // Rows of the board
    int rows_;
    // Columns of the board
    int cols_;
    // Stores de initial point
    Position initial_;
    // Stores the end point
    Position goal_;
    // Stores the board
    std::vector<std::vector<int> > board_;
};

#endif // _BOARD_H_