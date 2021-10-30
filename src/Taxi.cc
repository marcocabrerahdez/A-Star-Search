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
    xCoord = x;
    yCoord = y;
    direction_ = EAST;
}



int Taxi::get_Xcoord() const {
    return xCoord;
}



int Taxi::get_Ycoord() const {
    return yCoord;
}



/**
 * @brief Prints the taxi in the board on screen.
 */
void Taxi::print_taxi(void) {
  Colors color;
  switch (direction_) {
    case NORTH:
      std::cout << color.write_green("^");
      break;
    case EAST:
      std::cout << color.write_green(">");;
      break;
      case SOUTH:
      std::cout << color.write_green("v");;
      break;
    case WEST:
      std::cout << color.write_green("<");;
      break;  
  }
}


/**
 * @brief Prints the taxi in the board in a file.
 */
void Taxi::print_taxi(std::ofstream& fout) {
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