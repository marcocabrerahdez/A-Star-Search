#include "Board.h"
#include <fstream>

Board::Board(const int& rows, const int& cols) {
  assert(rows >= 0 && cols >= 0 && "Bad board dimensions:(");
    
  // Asignar posiciones inciales del tablero
  setRows(rows);
  setCols(cols);
  setBoard(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board_[i][j] = FREE;
    }
  }
}



int Board::getRows() {
  return rows_;
}



int Board::getCols() {
  return cols_;
}



int Board::getCell(const int& x, const int& y) {
    return board_[x][y];
}



void Board::setRows(const int& rows) {
  rows_ = rows;
}



void Board::setCols(const int& cols) {
  cols_ = cols;
}



void Board::setBoard(const int& rows, const int& cols) {
  board_.resize(rows);
    
  for (int i = 0; i < rows; i++) 
    board_[i].resize(cols);
}



void Board::changeState(const int& x, const int& y, const int& state) {
    board_[x][y] = state;
}



bool Board::createObstacle(const int& x, const int& y) {
    if(assert(x >= 0 && y >= 0 && "Obstacle outside dimensions:(");
    if (getCell(x, y) == 0) {
        changeState(x, y, 2);
        return true;
    }
    return false;
}



void Board::createRandomObstacle(int& KObstacles) {
  int row, col;
  int obstacle_counter = 0;

  srand(time(NULL));
  int area = getRows() * getCols();

  KObstacles >= area - 2 ? KObstacles = area - 2 : KObstacles;

  while (obstacle_counter < KObstacles) {
    row = rand() % getRows();
    col = rand() % getCols();
    if (createObstacle(row, col))
        obstacle_counter++;
  }
}


void Board::printCell(const int& x, const int& y) {
  switch (getCell(x, y)) {
    case FREE:
        std::cout << ".";
        break;

    case STEPPED:
        std::cout << "X";
        break;

    case OBSTACLE:
        std::cout << "█";
        break;

    case INITIAL:
        std::cout << "A";
        break;

    case END:
        std::cout << "B";
        break;
    
    default:
        break;
    }
}



void Board::printBoard(std::ostream& os) {
  for (int i = 0; i < getRows(); i++) {
      std::cout << "\n";
    for (int j = 0; j < getCols(); j++) {
      printCell(i, j);
    }
  }
  std::cout << std::endl;
}


int Board::readCoordFile(std::ifstream& coord_file) {
  int placed_obstacles_count = 0;
  int lines_read = 0;
  std::string x_string = " ";
  std::string y_string = " ";
  int x = 0;
  int y = 0;
  while (coord_file >> x_string >> y_string) {
      lines_read++;
      x = stoi(x_string);
      y = stoi(y_string);
      if (createObstacle(x, y)){
        placed_obstacles_count++;
      }
  }
  std::cout << "Numero de lineas leidas (1 linea = 1 obstaculo) :" << lines_read << std::endl; 
  return placed_obstacles_count;

}