/** 
 * Universidad de La Laguna
 * Asignatura: Inteligencia Artificial
 * Practica nº1: Búsqueda.
 * @author Marco Antonio Cabrera Hernández
 * @author Jose Antonio Trujillo Mendoza
 * @author Mario Hernández García
 * @class Taxi
 * @brief Creates a Taxi object to walk the path
 *  
 * 
 * @date 
 */
#include "../include/Cell.h"

Cell::Cell(int row, int col, int estado) {
  row_ = row;
  col_ = col;
  f_ = 0;
  g_ = 0;
  h_ = 0;
  parent_ = 0;
}



int Cell::get_estado() const {
  return estado_;
}



float Cell::get_costeG() const {
  return costeG_;
}



void Cell::set_estado(int estado) {
  estado_ = estado;
}



void Cell::set_costeG(float coste) {
    costeG_ = coste;
}