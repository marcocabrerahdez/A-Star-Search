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
    Board(void) = default;
    Board(const int& rows, const int& cols);

    int get_rows(void) const;
    int get_cols(void) const;
    // Reads the coordinates given from a file
    int read_coord_file(std::ifstream& coord_file);
    Cell& get_cell(const int& x, const int& y);
    void set_rows(const int& rows);
    void set_cols(const int& cols);
    // Set the neighbors of a specific cell for 4 directions
    void set_neightbors_4_directions(int i, int j);
    // Set the neighbors of a specific cell for 8 direction
    void set_neightbors_8_directions(int i, int j);
    void set_board(const int& rows, const int& cols);
    void set_heuristic(int option);
    // Changes the state of a specific cell of the board
    void change_state(const int& x, const int& y, const int& state);
    // Creates a random obstacles on the board
    void create_random_obstacle(float& obstacles);
    // Print a specific cell of the board
    void print_cell(const int& x, const int& y);
    // Print a specific cell of the board in a file
    void print_cell(const int& x, const int& y, std::ofstream& fout);
    // Store the cordinstes in s file
    void print_cell(const int& x, const int& y, std::ofstream& fout, int debug);
    // Prints the board on screen
    void print_board(Taxi taxi);
    // Prints the board in a file
    void print_board(Taxi taxi, std::ofstream& fout);
    // Store random obstacles in a file
    void print_board(Taxi taxi, std::ofstream& fout, bool debug);
    // Checks if the obstacle option is on
    bool create_obstacle(const int& x, const int& y);
    // Checks if the 
    bool is_in_set(const Cell& c, const std::vector<Cell>& s);
    // A* algorithm
    std::vector<Cell>& a_star(int xInicio, int yInicio, int xFinal, int yFinal, std::vector<Cell>& result, int moveset);
    // Take tha current cell and iterates over its parent
    void rebuild_path(std::vector<Cell>& v, Cell& actual, Cell I);
    // Checks for the optimize path
    bool optimal_path(int xInicio, int yInicio, int xFinal, int yFinal, Taxi& taxi, int moveset);
  private:
    // Rows of the board
    int rows_;
    // Columns of the board
    int cols_;
    // Stores the board
    std::vector<std::vector<Cell>> board_;
    // Heuristic function
    Heuristic* heuristic_;
    // Number of nodes that have been expanded
    long int expanded_nodes = 0;
};

#endif // _BOARD_H_