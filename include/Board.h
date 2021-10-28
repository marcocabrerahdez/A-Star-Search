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
#include "Cell.h"
#include "Taxi.h"
#include "Heuristic.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <vector>

class Board {
  public:
    Board() = default;
    Board(const int& rows, const int& cols);
    
    // Getters
    int getRows(void) const;
    int getCols(void) const;
    Cell& getCell(const int& x, const int& y);
    // Reads the coordinates given from a file
    int readCoordFile(std::ifstream& coord_file);
    Cell getInitial() const;
    Cell getGoal() const;
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
    // Prints the board
    void printBoard(Taxi taxi);
    // Prints the board in a file
    void printBoard(Taxi taxi, std::ofstream& fout);
    // Checks if the obstacle option is on
    bool createObstacle(const int& x, const int& y);

    bool is_in_set(const Cell& c, const std::vector<Cell>& s);
    std::vector<Cell> a_star(int xInicio, int yInicio, int xFinal, int yFinal);
    void gestionar_vecino(std::vector<Cell>& open, Cell celda_vecina);
    void reconstruir_camino(Cell celda);
    static int contador;
  private:
    // Rows of the board
    int rows_;
    // Columns of the board
    int cols_;
    // Stores the board
    std::vector<std::vector<Cell> > board_;

    Heurisitc* heuristic_;
};

#endif // _BOARD_H_