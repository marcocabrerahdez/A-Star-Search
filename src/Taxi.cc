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



int Taxi::getX_coord() const {
    return position_.xCoord;
}



int Taxi::getY_coord() const {
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





// @brief prints the board on screen
void Taxi::printBoard(Board taxi) {
  for (int i = 0; i < taxi.getRows(); i++) {
    std::cout << "\n";
    for (int j = 0; j < taxi.getCols(); j++) {
      if (i == getX_coord() && j == getY_coord())
        printTaxi();
      else 
        taxi.printCell(i, j);
    }
  }
  std::cout << std::endl;
}



// @brief prints the board on screen
void Taxi::printBoard(Board taxi, std::ofstream& fout) {
  for (int i = 0; i < taxi.getRows(); i++) {
    fout << "\n";
    for (int j = 0; j < taxi.getCols(); j++) {
      if (i == getX_coord() && j == getY_coord())
        printTaxi(fout);
      else 
        taxi.printCell(i, j, fout);
    }
  }
  fout << std::endl;
}
float Taxi::d_euclidea(const Board& i, const Position f) {
  Position goal_ = i.getGoal();
  return static_cast<float>(sqrt(pow((fabs(goal_.xCoord - f.xCoord)), 2) + (pow((fabs(goal_.yCoord - f.yCoord)), 2))));
}




float Taxi::d_manhattan(const Board& i, const Position f) {
  Position goal_ = i.getGoal();
  return static_cast<float>(fabs(static_cast<double>(goal_.xCoord - f.xCoord)) + fabs(static_cast<double>(goal_.yCoord - f.yCoord)));
}