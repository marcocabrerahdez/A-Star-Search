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
#include "Board.h"
#include "Position.h"

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
    float d_euclidea(const Board& board, const Position f);
    float d_manhattan(const Board& board, const Position f);
    std::vector<Position> get_neighbor_4(const Board& tablero) const;
    std::vector<Position> get_neighbor_8(const Board& tablero) const;
    // Prints the board
    void printBoard(Board taxi);
    // Prints the board in a file
    void printBoard(Board taxi, std::ofstream& fout);
    // Prints the taxi in the board
    void printTaxi();
    void printTaxi(std::ofstream& fout);
    void a_star(Board board, int option);
  private:
    // Specifies current direction of the taxi
    int direction_;

    float costeI_;
    float costeF_;
    // Specifies the current position of the taxi
    Position position_;
    // Store accesible board cordinates 4 or 8
    std::vector<Position> neighbors_;

    clock_t time_;
};

#endif // _TAXI_H