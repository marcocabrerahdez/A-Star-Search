#include "../include/Board.h"

Board::Board(const int& rows, const int& cols) {
  assert(rows >= 0 && cols >= 0 && "Bad board dimensions:(");
    
  // Assign initial board positions
  setRows(rows);
  setCols(cols);
  setBoard(rows, cols);

  // Initialize board dimensions
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board_[i][j] = FREE;
    }
  }
}



// @return rows of the board
int Board::getRows(void) const {
  return rows_;
}



// @return columns of the board
int Board::getCols(void) const {
  return cols_;
}



// @return a specific cell of the board
int Board::getCell(const int& x, const int& y) {
    return board_[x][y];
}

Position Board::getInitial() const {
  return initial_;
}

Position Board::getGoal() const {
  return goal_;
}

// @brief sets rows
void Board::setRows(const int& rows) {
  rows_ = rows;
}



// @brief sets columns
void Board::setCols(const int& cols) {
  cols_ = cols;
}



void Board::setInitial(const int& rows, const int& cols) {
  initial_.xCoord = rows;
  initial_.yCoord = cols;
}



void Board::setGoal(const int& rows, const int& cols) {
  goal_.xCoord = rows;
  goal_.yCoord = cols;
}



// @brief sets board dimensions
void Board::setBoard(const int& rows, const int& cols) {
  board_.resize(rows);
    
  for (int i = 0; i < rows; i++) 
    board_[i].resize(cols);
}




// @brief changes state of the cell
void Board::changeState(const int& x, const int& y, const int& state) {
    board_[x][y] = state;
}



// @brief creates an obstacle in a specicif position of the board
bool Board::createObstacle(const int& x, const int& y) {
  if(x >= 0 && y >= 0 && x <= getRows() && y <= getCols()) {
    if (getCell(x, y) == 0) {
      changeState(x, y, 2);
      return true;
    }
  }
  return false;
}



// @brief creates an obstacle in a random position of the board
void Board::createRandomObstacle(int& obstacles) {
  int row, col;
  int obstacle_counter = 0;

  srand(time(NULL));
  int area = getRows() * getCols();

  // If number of obstacles are greater than the area of the board, 
  // sets the maximum posible obstacles
  obstacles >= area - 2 ? obstacles = area - 2 : obstacles;

  while (obstacle_counter < obstacles) {
    row = rand() % getRows();
    col = rand() % getCols();
    if (createObstacle(row, col))
      obstacle_counter++;
  }
}



// @brief prints a cell on the board based on its state
void Board::printCell(const int& x, const int& y) {
  Colors color;
  switch (getCell(x, y)) {
    case FREE:
      std::cout << color.writeWhite("·");
      break;

    case STEPPED:
      std::cout << color.writeCyan("X");
      break;

    case OBSTACLE:
      std::cout << color.writeYellow("█");
      break;

    case INITIAL:
      std::cout << color.writeRed("A");
      break;

    case END:
      std::cout << color.writeBlue("B");
      break;
    
    default:
        break;
  }
}



// @brief prints a cell on the board based on its state
void Board::printCell(const int& x, const int& y, std::ofstream& fout) {
  switch (getCell(x, y)) {
    case FREE:
      fout << "·";
      break;

    case STEPPED:
      fout << "X";
      break;

    case OBSTACLE:
      fout << "█";
      break;

    case INITIAL:
      fout << "A";
      break;

    case END:
      fout << "B";
      break;
    
    default:
        break;
  }
}



// @brief reads a coordinate from a file and assigns it to a cell on the board
// @return count of obstacles placed in the board
int Board::readCoordFile(std::ifstream& coord_file) {
  int x = 0;
  int y = 0;
  int lines_read = 0;
  int placed_obstacles_count = 0;

  std::string x_string = " ";
  std::string y_string = " ";

  while (coord_file >> x_string >> y_string) {
    lines_read++;
    x = stoi(x_string);
    y = stoi(y_string);
    
    if (createObstacle(x, y))
      placed_obstacles_count++;
  }
  std::cout << "Numero de lineas leidas (1 linea = 1 obstaculo): " << lines_read << std::endl; 
  return placed_obstacles_count;
}


