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
#ifndef CELL_H_
#define CELL_H_

#include <limits.h>

#include <iostream>
#include <vector>

enum State {FREE, STEPPED, OBSTACLE, INITIAL, END, MATCHED};

class Cell {
  public:
    Cell();
    Cell(int xCoord, int yCoord, int state = 0, int g = INT_MAX , int f = INT_MAX);

    int get_state();
    int get_xCoord() const;
    int get_yCoord() const;
    int getf_();                             
    int getg_();                
    
    void set_state(int state);
    void setg_(int g);
    void setf_(int f); 

    std::pair<int,int> get_father() const;
    std::pair<int,int> get_father();
    void set_father(const Cell&);

    unsigned int neighbors_size();
    std::pair<int, int> get_neighbors(int i);
    // Adds a neihbors to a specific cell
    void add_neighbor(const Cell&);
  private:  
    int xCoord_;                          
    int yCoord_;
    // Current state of the cell
    int state_;
    // Cost of the path from the starting node to node n
    int g_;           
    // Estimated total cost of the cheapest solution going through node n                 
    int f_;                             
    // Neighbors of the cell
    std::vector<std::pair<int, int> > neighbors_;
    // Father of the cell
    std::pair<int, int> father_;
};

#endif // CELL_H_