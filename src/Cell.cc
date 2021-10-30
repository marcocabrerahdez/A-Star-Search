#include "../include/Cell.h"

Cell::Cell():xCoord_(0), yCoord_(0), state_(FREE), g_(INT_MAX), f_(INT_MAX) {
  father_ = std::make_pair(0, 0);
}



Cell::Cell(int xCoord, int yCoord, int state, int g, int f) : 
          xCoord_(xCoord), yCoord_(yCoord), state_(state), g_(g), f_(f) {
  if(state_ < 0 || state_ > 3){
    state_ = 0;               
  }
  father_ = std::make_pair(0, 0);
}



int Cell::get_state(void) { 
  return state_; 
}



void Cell::set_state(int state) { 
  state_ = state; 
}



int Cell::get_xCoord() const { 
  return xCoord_; 
}



int Cell::get_yCoord() const { 
  return yCoord_; 
}



int Cell::getf_(){ 
  return f_; 
}



void Cell::setf_(int f) { 
  f_ = f; 
}



int Cell::getg_() { 
  return g_; 
}



void Cell::setg_(int g) { 
  g_ = g; 
}



std::pair<int,int> Cell::get_father() const {
  return father_;
}



std::pair<int,int> Cell::get_father() {
  return father_;
}


void Cell::set_father(const Cell& c){
  father_ = std::make_pair(c.get_xCoord(), c.get_yCoord());
}



unsigned int Cell::neighbors_size(){ 
  return neighbors_.size(); 
}



std::pair<int, int> Cell::get_neighbors(int i){
  return neighbors_[static_cast<int>(i)];
}



void Cell::add_neighbor(const Cell& c){
  neighbors_.push_back(std::make_pair(c.get_xCoord(), c.get_yCoord()));
}