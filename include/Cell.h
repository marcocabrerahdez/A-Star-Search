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
#ifndef CELL_H_
#define CELL_H_

#include <iostream>

enum State {FREE, STEPPED, OBSTACLE, INITIAL, END};

class Cell {
  public:
    Cell(void);
    Cell(int row, int col, int estado);
    int get_estado(void) const;
    float get_costeG(void) const;
    void set_estado(int estado);
    void set_costeG(float coste);
  private:
    int row_;
    int col_;
    double f_; // Costo estimado desde nodo inicial a nodo objetivo (g(n) + h(n))
    double h_; // Costo estimado desde este nodo al nodo objetivo
    double g_; // Coste desde el nodo inicial a este nodo
};

#endif // CELL_H_