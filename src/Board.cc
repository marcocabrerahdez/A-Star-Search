#include "../include/Board.h"

Board::Board(const int& rows, const int& cols) {
  assert(rows >= 0 && cols >= 0 && "Bad board dimensions:(");
  // Assign initial board positions
  set_rows(rows);
  set_cols(cols);
  set_board(rows, cols);
  // Initialize board dimensions
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board_[i][j].set_state(FREE);
    }
  }
}



// @return rows of the board
int Board::get_rows(void) const {
  return rows_;
}



// @return columns of the board
int Board::get_cols(void) const {
  return cols_;
}



// @return a specific cell of the board
Cell& Board::get_cell(const int& x, const int& y) {
  return board_[x][y];
}



// @brief sets rows
void Board::set_rows(const int& rows) {
  rows_ = rows;
}



// @brief sets columns
void Board::set_cols(const int& cols) {
  cols_ = cols;
}



// @brief sets board dimensions
void Board::set_board(const int& rows, const int& cols) {
  board_.resize(rows);
  for (int i = 0; i < rows; i++) {
    board_[i].resize(cols);
  }
  for (unsigned int i = 0; i < board_.size(); i++) {
    for (unsigned int j = 0; j < board_[i].size(); j++) {
      Cell aux(i, j);
      board_[i][j] = aux;
    }
  }
}



// @brief changes state of the cell
void Board::change_state(const int& x, const int& y, const int& state) {
  board_[x][y].set_state(state);
}



// @brief creates an obstacle in a specicif position of the board
bool Board::create_obstacle(const int& x, const int& y) {
  Cell dummy;
  if(x >= 0 && y >= 0 && x <= get_rows() && y <= get_cols()) {
    dummy = get_cell(x, y);
    if (dummy.get_state() == 0) {
      change_state(x, y, 2);
      return true;
    }
  }
  return false;
}



// @brief creates an obstacle in a random position of the board
void Board::create_random_obstacle(float& obstacles_percentage) {
  int row, col;
  int obstacle_counter = 0;
  srand(time(NULL));
  int obstacles = (get_rows() * get_cols()) * (obstacles_percentage / 100);
  int area = (get_rows() * get_cols());
  // If number of obstacles are greater than the area of the board, 
  // sets the maximum posible obstacles
  obstacles >= area - 2 ? obstacles = area - 2 : obstacles;
  while (obstacle_counter < obstacles) {
    row = rand() % get_rows();
    col = rand() % get_cols();
    if (create_obstacle(row, col))
      obstacle_counter++;
  }
}



// @brief prints a cell on the board based on its state
void Board::print_cell(const int& x, const int& y) {
  Colors color;
  Cell dummy = get_cell(x, y);
  switch (dummy.get_state()) {
    case FREE:
      std::cout << color.write_white("·");
      break;

    case STEPPED:
      std::cout << color.write_cyan("X");
      break;

    case OBSTACLE:
      std::cout << color.write_yellow("█");
      break;

    case INITIAL:
      std::cout << color.write_red("A");
      break;

    case END:
      std::cout << color.write_blue("B");
      break;

    case MATCHED:
      std::cout << color.write_blue("*");
      break;
    
    default:
        break;
  }
}



// @brief prints a cell on the board based on its state
void Board::print_cell(const int& x, const int& y, std::ofstream& fout) {
  Cell dummy = get_cell(x, y);
  switch (dummy.get_state()) {
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
    case MATCHED:
      fout << "*";
      break;

    default:
        break;
  }
}




void Board::print_cell(const int& x, const int& y, std::ofstream& fout, int debug) {
  Cell dummy = get_cell(x, y);
  if (dummy.get_state() == OBSTACLE){
    fout << x << " " << y << std::endl;
  }
}




// @brief reads a coordinate from a file and assigns it to a cell on the board
// @return count of obstacles placed in the board
int Board::read_coord_file(std::ifstream& coord_file) {
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
    
    if (create_obstacle(x, y))
      placed_obstacles_count++;
  }
  std::cout << "Numero de lineas leidas (1 linea = 1 obstaculo): " << lines_read << std::endl; 
  return placed_obstacles_count;
}



// @brief prints the board on screen
void Board::print_board(Taxi taxi) {
  for (int i = 0; i < get_rows(); i++) {
    std::cout << "\n";
    for (int j = 0; j < get_cols(); j++) {
      if (i == taxi.get_Xcoord() && j == taxi.get_Ycoord())
        taxi.print_taxi();
      else 
        print_cell(i, j);
    }
  }
  std::cout << std::endl;
}



// @brief prints the board on screen
void Board::print_board(Taxi taxi, std::ofstream& fout) {
  for (int i = 0; i < get_rows(); i++) {
    fout << "\n";
    for (int j = 0; j < get_cols(); j++) {
      if (i == taxi.get_Xcoord() && j == taxi.get_Ycoord())
        taxi.print_taxi(fout);
      else 
        print_cell(i, j, fout);
    }
  }
  fout << std::endl;
}


void Board::print_board(Taxi taxi, std::ofstream& fout, bool debug) {
  for (int i = 0; i < get_rows(); i++) {
    for (int j = 0; j < get_cols(); j++) {
      if (i == taxi.get_Xcoord() && j == taxi.get_Ycoord()){
        continue;
      }
      else{ 
        print_cell(i, j, fout, debug);
      }
    }
  }
  fout << std::endl;
}


bool Board::is_in_set(const Cell& c, const std::vector<Cell>& s){
  for(unsigned int i = 0; i < s.size(); i++) {
    if(s[i].get_xCoord() == c.get_xCoord() && s[i].get_yCoord()== c.get_yCoord())
      return true;
  }
  return false;
}



std::vector<Cell>& Board::a_star(int xInicio, int yInicio, int xFinal, int yFinal, std::vector<Cell>& result, int moveset) {                                            
  std::vector<Cell> open_set;
  std::vector<Cell> closed_set;
  Cell& initial = board_[xInicio][yInicio];
  Cell& Final = board_[xFinal][yFinal];
  Cell* fail_result = &Final;
  initial.setg_(0);                                               
  initial.setf_((*heuristic_)(initial, Final));

  open_set.push_back(initial);                                     
  while(!open_set.empty()){
    unsigned int winner = 0;
    for(unsigned int i = 0; i < open_set.size(); i++) {     
      // nos quedamos con el camino de menor coste      
      if(open_set[i].getf_() < open_set[winner].getf_())
        winner = i;
    }
    Cell& actual = board_[open_set[winner].get_xCoord()][open_set[winner].get_yCoord()]; 
    fail_result = &actual;
    // Si es la misma celda -> Hemos llegado al final con camino óptimo
    if((actual.get_xCoord() == xFinal) && (yFinal == actual.get_yCoord())) { 
      rebuild_path(result, actual, initial);
      return result;
    }
    open_set.erase(open_set.begin() + winner);
    if (moveset == 4){
      set_neightbors_4_directions(actual.get_xCoord(),actual.get_yCoord());
    }
    else set_neightbors_8_directions(actual.get_xCoord(),actual.get_yCoord());

    expanded_nodes++;                
    closed_set.push_back(actual);

    for(unsigned int i = 0; i < actual.neighbors_size(); i++) {                 
      int x = actual.get_neighbors(i).first;
      int y = actual.get_neighbors(i).second;
      Cell& neighbor = board_[x][y];            
      if(is_in_set(neighbor, closed_set))
          continue;

      int tent_g = actual.getg_() + 1;

      if(!is_in_set(neighbor, open_set)) {
      // Este camino es el mejor! Guárdalo
        board_[neighbor.get_xCoord()][neighbor.get_yCoord()].set_father(actual);
        board_[neighbor.get_xCoord()][neighbor.get_yCoord()].setg_(tent_g);
        board_[neighbor.get_xCoord()][neighbor.get_yCoord()].setf_(tent_g + (*heuristic_)(neighbor, Final));
        open_set.push_back(neighbor);
        //contador++;
      }
      else if(tent_g >= neighbor.getg_())
        continue;

    }
  }
  rebuild_path(result, *fail_result, initial);
  return result;
}



void Board::rebuild_path(std::vector<Cell>& v, Cell& actual, Cell i) {
  Cell& aux = actual;
  v.push_back(aux);
  while ((aux.get_xCoord() != i.get_xCoord()) || (aux.get_yCoord() != aux.get_yCoord())) {
    aux = board_[static_cast<int>(aux.get_father().first)][static_cast<int>(aux.get_father().second)];
    v.push_back(aux);
  }
}

bool Board::optimal_path(int xInicio, int yInicio, int xFinal, int yFinal, Taxi& taxi, int moveset) {
  if(board_[xInicio][yInicio].get_state() == 3){
      board_[xInicio][yInicio].set_state(3);
  }
  if(board_[xFinal][yFinal].get_state() == 4){
    board_[xFinal][yFinal].set_state(4);
    if (moveset == 4){
      if(static_cast<int>(xFinal) - 1 >= 0){
        set_neightbors_4_directions(xFinal - 1, yFinal);
      }
      if(xFinal + 1 < static_cast<int>(board_.size())){
        set_neightbors_4_directions(xFinal + 1, yFinal);
      }
      if(static_cast<int>(yFinal) - 1 >= 0){
        set_neightbors_4_directions(xFinal, yFinal - 1);
      }
      if(yFinal + 1 < static_cast<int>(board_[0].size())){
        set_neightbors_4_directions(xFinal, yFinal + 1);
      } 
    }
    if (moveset == 8){
      if(static_cast<int>(xFinal) - 1 >= 0){
        set_neightbors_8_directions(xFinal - 1, yFinal);
      }
      if(xFinal + 1 < static_cast<int>(board_.size())){
        set_neightbors_8_directions(xFinal + 1, yFinal);
      }
      if(static_cast<int>(yFinal) - 1 >= 0){
        set_neightbors_8_directions(xFinal, yFinal - 1);
      }
      if(yFinal + 1 < static_cast<int>(board_[0].size())){
        set_neightbors_8_directions(xFinal, yFinal + 1);
      }
    }
  }
  long time_init = clock();
  bool exists;
  std::vector<Cell> result;
  std::vector<Cell>& result2 = a_star(xInicio, yInicio, xFinal, yFinal, result, moveset);
  long time_final = clock();
  double time = double((time_final - time_init));
  float seconds = time/CLOCKS_PER_SEC;
  std::cout << "Tiempo de ejecución (ciclos 1M/s): " << time << std::endl << "Tiempo de ejecución (segundos): " << seconds << std::endl;
  std::cout << "Nodos expandidos: " << expanded_nodes << std::endl;
  unsigned int i = 0;
  if (result2.size()>0){
    Taxi taxi2(result2[0].get_xCoord(), result2[0].get_yCoord());
    taxi = taxi2;
  }
  else {
    exists = false;
    return exists;
  }
  for (i = 0; i < result2.size(); i++) {
    result2[i].set_state(1);
    board_[result2[i].get_xCoord()][result2[i].get_yCoord()].set_state(result2[i].get_state());
    if (result2[i].get_xCoord() == xFinal && result2[i].get_yCoord() == yFinal) exists = true;
  }
  board_[xFinal][yFinal].set_state(5);
  return exists;
}


void Board::set_heuristic(int option) {
  if (option == 1){
      heuristic_ = new d_manhattan();
  }
  else{
      heuristic_ = new d_euclidea();
  }
}




void Board::set_neightbors_4_directions(int i, int j) {
  if(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].get_state() != 2) {
    //UP
    if(i - 1 >= 0){
      if(board_[static_cast<unsigned int>(i - 1)][static_cast<unsigned int>(j)].get_state() != 2) {
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i-1)][static_cast<unsigned int>(j)]);
      }
    }
    //DOWN
    if(static_cast<unsigned int>(i + 1) < board_.size()){
      if(board_[static_cast<unsigned int>(i + 1)][static_cast<unsigned int>(j)].get_state() != 2) {
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i + 1)][static_cast<unsigned int>(j)]);
      }
    }
    //LEFT
    if(j - 1 >= 0){
      if(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j - 1)].get_state() != 2) {
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j - 1)]);
      }
    }
    //RIGHT
    if(static_cast<unsigned int>(j + 1) < board_[static_cast<unsigned int>(i)].size()){
      if(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j + 1)].get_state() != 2) {
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j + 1)]);
      }
    }
  }
}




void Board::set_neightbors_8_directions(int i, int j){
  if(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].get_state() != 2){
    //UP
    if(i - 1 >= 0){
      if(board_[static_cast<unsigned int>(i - 1)][static_cast<unsigned int>(j)].get_state() != 2){
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i - 1)][static_cast<unsigned int>(j)]);
      }
    }
    //DOWN
    if(static_cast<unsigned int>(i + 1) < board_.size()){
      if(board_[static_cast<unsigned int>(i + 1)][static_cast<unsigned int>(j)].get_state() != 2){
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i + 1)][static_cast<unsigned int>(j)]);
      }
    }
    //LEFT
    if(j - 1 >= 0){
      if(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j - 1)].get_state() != 2){
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j - 1)]);
      }
    }
    //RIGHT
    if(static_cast<unsigned int>(j + 1) < board_[static_cast<unsigned int>(i)].size()){
      if(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j + 1)].get_state() != 2){
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j + 1)]);
      }
    }
    //UP-LEFT
    if(i - 1 >= 0 && j-1 >= 0){
      if(board_[static_cast<unsigned int>(i-1)][static_cast<unsigned int>(j-1)].get_state() != 2){
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i - 1)][static_cast<unsigned int>(j - 1)]);
      }
    }
    //DOWN-LEFT
    if((static_cast<unsigned int>(i + 1) < board_[static_cast<unsigned int>(i)].size()) && (j - 1 >= 0)){
      if(board_[static_cast<unsigned int>(i + 1)][static_cast<unsigned int>(j - 1)].get_state() != 2){
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i + 1)][static_cast<unsigned int>(j - 1)]);
      }
    }
    //DOWN-RIGHT
    if((static_cast<unsigned int>(i + 1) < board_[static_cast<unsigned int>(i)].size()) && (static_cast<unsigned int>(j + 1) < board_[static_cast<unsigned int>(i + 1)].size())){
      if(board_[static_cast<unsigned int>(i + 1)][static_cast<unsigned int>(j + 1)].get_state() != 2){
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i + 1)][static_cast<unsigned int>(j + 1)]);
      }
    }
    //UP-RIGHT
    if(i - 1 >= 0 && (static_cast<unsigned int>(j + 1) < board_[static_cast<unsigned int>(i - 1)].size())){
      if(board_[static_cast<unsigned int>(i - 1)][static_cast<unsigned int>(j + 1)].get_state() != 2){
        board_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].add_neighbor(board_[static_cast<unsigned int>(i - 1)][static_cast<unsigned int>(j + 1)]);
      }
    }
  }
}