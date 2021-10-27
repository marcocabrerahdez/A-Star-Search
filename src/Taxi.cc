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

Position Taxi::getPosition_coord() const;
    return position_;



std::vector<Position> Taxi::get_neighbors(){
  return neighbors_;
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
void Taxi::printBoard(Board tablero) {
  for (int i = 0; i < tablero.getRows(); i++) {
    std::cout << "\n";
    for (int j = 0; j < tablero.getCols(); j++) {
      if (i == getX_coord() && j == getY_coord())
        printTaxi();
      else 
        tablero.printCell(i, j);
    }
  }
  std::cout << std::endl;
}



// @brief prints the board on screen
void Taxi::printBoard(Board tablero, std::ofstream& fout) {
  for (int i = 0; i < tablero.getRows(); i++) {
    fout << "\n";
    for (int j = 0; j < tablero.getCols(); j++) {
      if (i == getX_coord() && j == getY_coord())
        printTaxi(fout);
      else 
        tablero.printCell(i, j, fout);
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


void Taxi::get_neighbor_4(const Board& tablero) const {
}



void Taxi::a_star(Board board, int option) {
  float min;
  int pos = 0;
  time_ = clock();
  std::vector<Cell> open;
  Cell actual_ = getPosition_coord();

  actual_.set_costeG(0.0);
  actual_.set_costeF(heuristicas(actual_));
  open.push_back(actual_);
  actual_.set_abierta(true);
  
  while (!open.empty()) {
    min = MAXFLOAT;
    for (unsigned int i = 0; i < open.size(); i++) {
      if (open[i].get_costeF() < min) { 
        min = open[i].get_costeF();
        actual_ = open[i];
        pos = i;
      }
    }
    open.erase(open.begin() + pos);
    actual_ -> set_abierta(false);
    actual_ -> set_cerrada(true);

    if (!sensor_norte(tablero))
      gestionar_vecino(open, tablero.get_celda(actual_ -> get_i() - 1, actual_ -> get_j()));
    if (!sensor_sur(tablero))
      gestionar_vecino(open, tablero.get_celda(actual_ -> get_i() + 1, actual_ -> get_j()));
    if (!sensor_oeste(tablero))
      gestionar_vecino(open, tablero.get_celda(actual_ -> get_i(), actual_ -> get_j() - 1));
    if (!sensor_este(tablero))
      gestionar_vecino(open, tablero.get_celda(actual_ -> get_i(), actual_ -> get_j() + 1));
  time_ = clock() - time_;
  return false;
}


void Taxi::gestionar_vecino(std::vector<Cell>& open, Cell& celda_vecina) {
  float costeG = actual_.get_costeG() + 1.0;
  if (celda_vecina.get_cerrada()) {
    if (costeG < celda_vecina.get_costeG()) {
      celda_vecina = FREE;
      open.push_back(celda_vecina);
    } else {
        return;
    }
  } else if (celda_vecina == FREE) {
      if (costeG >= celda_vecina.get_costeG()) {
        return;
      }
  } else {
      celda_vecina = FREE;
      open.push_back(celda_vecina);
  }
  celda_vecina.set_costeG(costeG);
  celda_vecina.set_costeF(costeG + heuristicas(celda_vecina));
  celda_vecina.set_padre(actual_); 
} 