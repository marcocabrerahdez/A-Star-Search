#include "Board.h"

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



bool createObstacle(const int& x, const int& y) {
    if (getCell(row, col) == 0) {
        changeState(x, y, OBSTACLE);
        return true;
}



void Board::createRandomObstacle(int& KObstacles) {
  int row, col;
  int obstacle_counter = 0;

  srand(time(NULL));
  int area = getRows() * getCols();

  KObstacles >= area - 2 ? KObstacles = area - 2 : KObstacles = KObstacles;

  while (obstacle_counter <= KObstacles) {
    row = rand() % getRows();
    col = rand() % getCols();
    if (createObstacle(row, col))
        obstacle_counter++;
    }
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
      printCell(i, j) << " ";
    }
  }
}


int Board::readCoordFile(std::ifstream& coord_file) {
  coord_file.open();
  int placed_obstacles_count = 0;
  int x = 0;
  int y = 0;
  while (!coord_file.eof()){
      cin << x << y;
      if ((x >= 0) && (x <= getRows()) && (y >= 0) && (y <= getCols()))
        createObstacle(x, y, 2);

  }


}