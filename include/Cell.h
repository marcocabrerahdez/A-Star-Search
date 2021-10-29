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
#include <vector>
#include <limits.h>

enum State {FREE, STEPPED, OBSTACLE, INITIAL, END};

class Cell {
  public:
    Cell();
    Cell(int x, int y, int valor = 0, int g = INT_MAX , int f = INT_MAX);

    int getValor();
    int getX() const;
    int getY() const;
    int getf_();                             
    int getg_();                
    
    void setValor(int valor);
    void setg_(int g);
    void setf_(int f); 

    std::pair<int,int> getPadre() const;
    std::pair<int,int> getPadre();
    void setPadre(const Cell&);

    unsigned int sizeVecinos();
    Cell& getVecino(int i);
    void resetVecinos();
    void addVecino(Cell&, int);
    int getDirection();
    void setDirection(int);
  private:  
    int valor_;
    int g_;                            
    int f_;                             
    int x_;                          
    int y_;
    std::vector<Cell> vecinos_;
    std::pair<int, int> padre_;
    int relative_direction;
};

#endif // CELL_H_