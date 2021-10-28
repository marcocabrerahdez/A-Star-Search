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
      board_[i][j].setValor(FREE);
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
Cell& Board::getCell(const int& x, const int& y) {
    return board_[x][y];
}



// @brief sets rows
void Board::setRows(const int& rows) {
  rows_ = rows;
}



// @brief sets columns
void Board::setCols(const int& cols) {
  cols_ = cols;
}



// @brief sets board dimensions
void Board::setBoard(const int& rows, const int& cols) {
  board_.resize(rows);
    
  for (int i = 0; i < rows; i++) 
    board_[i].resize(cols);
}




// @brief changes state of the cell
void Board::changeState(const int& x, const int& y, const int& state) {
  board_[x][y].setValor(state);
}



// @brief creates an obstacle in a specicif position of the board
bool Board::createObstacle(const int& x, const int& y) {
  Cell dummy;
  if(x >= 0 && y >= 0 && x <= getRows() && y <= getCols()) {
    dummy = getCell(x, y);
    if (dummy.getValor() == 0) {
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
  Cell dummy = getCell(x, y);
  switch (dummy.getValor()) {
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
  Cell dummy = getCell(x, y);
  switch (dummy.getValor()) {
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



// @brief prints the board on screen
void Board::printBoard(Taxi taxi) {
  for (int i = 0; i < getRows(); i++) {
    std::cout << "\n";
    for (int j = 0; j < getCols(); j++) {
      if (i == taxi.getX_coord() && j == taxi.getY_coord())
        taxi.printTaxi();
      else 
        printCell(i, j);
    }
  }
  std::cout << std::endl;
}



// @brief prints the board on screen
void Board::printBoard(Taxi taxi, std::ofstream& fout) {
  for (int i = 0; i < getRows(); i++) {
    fout << "\n";
    for (int j = 0; j < getCols(); j++) {
      if (i == taxi.getX_coord() && j == taxi.getY_coord())
        taxi.printTaxi(fout);
      else 
        printCell(i, j, fout);
    }
  }
  fout << std::endl;
}



bool Board::is_in_set(const Cell& c, const std::vector<Cell>& s){
  for(unsigned int i = 0; i < s.size(); i++) {
    if(s[i].getX() == c.getX() && s[i].getY() == c.getY())
      return true;
  }
  return false;
}


// No funciona bien aun, falta buscar camino minimo
std::vector<Cell> Board::a_star(int xInicio, int yInicio, int xFinal, int yFinal) {
  std::vector<Cell> result;                                             
  std::vector<Cell> setAbierto;
  std::vector<Cell> setCerrado;
  Cell& Inicial = board_[xInicio][yInicio];
  Cell& Final = board_[xFinal][yFinal];

  Inicial.setg_(0);                                                  
  Inicial.setf_((*heuristic_)(Inicial, Final));

  setAbierto.push_back(Inicial);                                     
  contador++;

  while(!setAbierto.empty()){
    unsigned int winner = 0;
    for(unsigned int i = 0; i < setAbierto.size(); i++) {     
      // nos quedamos con el camino de menor coste      
      if(setAbierto[i].getf_() < setAbierto[winner].getf_())
        winner = i;
    }
    Cell actual = board_[setAbierto[winner].getX()][setAbierto[winner].getY()]; 
    // Si es la misma celda -> Hemos llegado al final con camino óptimo
    if((actual.getX() == xFinal) && (yFinal == actual.getY())) {  
      // -> Funcion de reconstruir camno (Propagar) 
      return result;
    }
    setAbierto.erase(setAbierto.begin() + winner);                
    setCerrado.push_back(actual);
    // Miramos los vecinos de la Celda actual
    for(int i = 0; i < actual.sizeVecinos(); i++) {                 
      int x = actual.getVecino(i).first;
      int y = actual.getVecino(i).second;
      Cell vecino = board_[x][y];              
      if(is_in_set(vecino, setCerrado))
          continue;

      int tent_g = actual.getg_() + 1;

      if(!is_in_set(vecino, setAbierto)) {
        setAbierto.push_back(vecino);
        contador++;
      }
      else if(tent_g >= vecino.getg_())
        continue;

      // Este camino es el mejor! Guárdalo
      board_[vecino.getX()][vecino.getY()].setPadre(actual);
      board_[vecino.getX()][vecino.getY()].setg_(tent_g);
      board_[vecino.getX()][vecino.getY()].setf_(tent_g + (*heuristic_)(vecino, Final));
    }
  }
  return result;
}