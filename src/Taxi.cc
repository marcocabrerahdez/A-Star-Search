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
#include "../include/Taxi.h"

Taxi::Taxi(const int& x, const int& y) {
    position_.xCoord = x;
    position_.yCoord = y;
    direction_ = EAST;
}



int Taxi::getX_coord(){
    return position_.xCoord;
}



int Taxi::getY_coord(){
    return position_.yCoord;
}



void Taxi::printTaxi(void) {
  Colors color;
  switch (direction_) {
    case NORTH:
      std::cout << color.writeGreen("^");
      break;
    case EAST:
      std::cout << color.writeGreen(">");;
      break;
      case SOUTH:
      std::cout << color.writeGreen("v");;
      break;
    case WEST:
      std::cout << color.writeGreen("<");;
      break;  
  }
}



void Taxi::printTaxi(std::ofstream& fout) {
  switch (direction_) {
    case NORTH:
      fout << "^";
      break;
    case EAST:
      fout << ">";
      break;
      case SOUTH:
      fout << "v";
      break;
    case WEST:
      fout << "<";
      break;  
  }
}