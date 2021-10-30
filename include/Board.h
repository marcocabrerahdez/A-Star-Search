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
 * @date 02/11/2021
*/
#ifndef _BOARD_H_
#define _BOARD_H_

#include "Colors.h"
#include "Cell.h"
#include "Taxi.h"
#include "Heuristic.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

class Board {
  public:
    Board() = default;
    Board(const int& rows, const int& cols);
    // Getters
    int getRows(void) const;
    int getCols(void) const;
    // Reads the coordinates given from a file
    int readCoordFile(std::ifstream& coord_file);
    Cell& getCell(const int& x, const int& y);
    // Setters
    void setRows(const int& rows);
    void setCols(const int& cols);
    // Set the neighbors of the cell
    void setVecinos();
    // Set the neighbors of a specific cell
    void setVecino(int i, int j);
    void setBoard(const int& rows, const int& cols);
    void setHeuristic(int option);
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
    std::vector<Cell>& a_star(int xInicio, int yInicio, int xFinal, int yFinal, std::vector<Cell>& result);
    void gestionar_vecino(std::vector<Cell> open, Cell celda_vecina);
    void reconstruir_camino(std::vector<Cell>& v, Cell& actual, Cell I);
    bool caminoOptimo(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal, Taxi& taxi);


    long int expanded_nodes = 0;

  private:
    // Rows of the board
    int rows_;
    // Columns of the board
    int cols_;
    // Stores the board
    std::vector<std::vector<Cell> > board_;
    
    Heuristic* heuristic_;

};

#endif // _BOARD_H_