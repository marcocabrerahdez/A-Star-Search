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



void createObsatcle() {

}



void Board::printCell(const int& x, const int& y) {
    switch (getCell(x, y)) {
    case FREE:
        std::cout << ".";
        break;

    case PASSED:
        std::cout << "X";
        break;

    case OBSTACLE:
        std::cout << "";
        break;
    
    default:
        break;
    }
}



std::ostream& Board::printBoard(std::ostream& os) {
  for (int i = 0; i < getRows(); i++) {
    for (int j = 0; j < getCols(); j++) {
      os << printCell(i, j) << " ";
    }
    os << "\n";
  }
}