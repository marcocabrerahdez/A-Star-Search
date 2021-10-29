#include "../include/Cell.h"

Cell::Cell():valor_(FREE), g_(INT_MAX), f_(INT_MAX), x_(0), y_(0) {
    padre_ = std::make_pair(0, 0);
}


Cell::Cell(int x, int y, int valor, int g, int f): valor_(valor), g_(g), f_(f), x_(x), y_(y) {
  if(valor_ < 0 || valor_ > 3){
      valor_ = 0;               
  }
  padre_ = std::make_pair(0, 0);
}



int Cell::getValor() { 
  return valor_; 
}



void Cell::setValor(int valor) { 
  valor_ = valor; 
}



int Cell::getX()const { 
  return x_; 
}



int Cell::getY() const { 
  return y_; 
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



std::pair<int,int> Cell::getPadre(){
  return padre_;
}



std::pair<int,int> Cell::getPadre() const{
  return padre_;
}



void Cell::setPadre(const Cell& c){
  padre_ = std::make_pair(c.getX(), c.getY());
}



unsigned int Cell::sizeVecinos(){ 
  return vecinos_.size(); 
}



Cell& Cell::getVecino(int i){
  return vecinos_[static_cast<int>(i)];
}



void Cell::resetVecinos(){
  vecinos_.clear();
}



void Cell::addVecino(Cell& c, int relative_direction){
  c.setDirection(relative_direction);
  vecinos_.push_back(c);
}

void Cell::setDirection(int direction){
  relative_direction = direction;
}

int Cell::getDirection(){
  return relative_direction;
}
