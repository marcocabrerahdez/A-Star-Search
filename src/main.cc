/** 
 * Universidad de La Laguna
 * Asignatura: Inteligencia Artificial
 * Practica nº1: Búsqueda.
 * @author Marco Cabrera Hernández
 * @author Jose Antonio Trujillo Mendoza
 * @author Mario Hernández García
 * @class Taxi
 * @brief Creates a Taxi object to walk the path
 *  
 * 
 * @date 
 */
#include "../include/Board.h"

/*
#include "Board.cc"
#include "Taxi.cc"
#include "Heuristic.cc"
#include "Cell.cc"
#include "Colors.cc"
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include <sys/ioctl.h>
#include <unistd.h>

int main(void){
    int M = 0; //filas
    int N = 0; //columnas
    int opcion = 0;
    int op = 10;
    int X_puntoA, X_puntoB = 0;
    int Y_puntoA, Y_puntoB = 0;
    int read_lines = 0;
    bool print_file = false;
    bool out_of_bounds = true;
    
    std::ifstream fichero;
    std::ofstream fichero_out;
    std::ofstream coord_out;
    std::string file_name;

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    //std::cout << getenv("EDITOR");

    std::cout << "----------------Practica nº1: Búsqueda--------------" << std::endl;
    std::cout << "Introduzca el tamaño de la matriz (MxN):" << std::endl << "M: ";
    std::cin >> M;
    std::cout << "N (tamaño máximo: " << w.ws_col << " ): ";
    std::cin >> N;
    if(M <= 0 || N <= 0){
      std::cout << "No se puede crear un tablero con M o N <= 0" << std::endl;
      return 1;
    }
    if (N > w.ws_col) {
      while (op != 0 && op != 1 && op != 2) {
        std::cout << "Se ha superado el tamaño máximo de N, afecta a su visualización, quiere sacarlo por fichero (0), introducir un N menor (1) o intentarlo otra vez con una ventana mayor (2)?" << std::endl;
        std::cin >> op;
        if (op == 2) {
          ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
          if (N > w.ws_col) op = 5;
        }
      }
      if (op == 1){
        std::cout << "N (tamaño máximo: " << w.ws_col << " ): ";
        std::cin >> N;
      }
      if (op == 0) {
        print_file = true;
      }
    }

    Board tablero(M, N);

    while (out_of_bounds){
      std::cout << "Indique el punto inicial (x): ";
      std::cin >> X_puntoA;

      std::cout << "Indique el punto inicial (y): ";
      std::cin >> Y_puntoA;

      std::cout << "Indique el punto final (x): ";
      std::cin >> X_puntoB;

      std::cout << "Indique el punto final (y) ";
      std::cin >> Y_puntoB;
      if (X_puntoA < 0 || X_puntoA > M || Y_puntoA < 0 || Y_puntoA > N || X_puntoB < 0 || X_puntoB > M || Y_puntoB < 0 || Y_puntoB > N){
        out_of_bounds = true;
        std::cout << "Ha introducido algun valor fuera del rango M: " << M << " N: " << N << std::endl;
      }
      else out_of_bounds = false;
    }
    Taxi taxi(X_puntoA, Y_puntoA);
    tablero.change_state(X_puntoA,Y_puntoA,3);
    tablero.change_state(X_puntoB,Y_puntoB,4);

    int opcion_heuristica = 0;
    out_of_bounds = false;
    //while (opcion_heuristica >= 0 || opcion_heuristica <= 1){
      //if (out_of_bounds == true){
        //std::cout << "Opcion no correcta, vuelva a introducirlo" << std::endl;
      //}
      std::cout << "¿Que heuristica quieres utilizar (0 ecludiana, 1 manhattan)" << std::endl;
      std::cin >> opcion_heuristica;
      //out_of_bounds = true;
    //}
    std::cout << "¿Quiere introducir los obstáculos por pantalla o cargar un fichero de coordenadas (X,Y)? (0 por fichero, 1 por pantalla)" << std::endl;
    std::cin >> opcion;
    switch (opcion) {
      case 0:
        std::cout << "Introduzca el nombre del fichero:" << std::endl;
        std::cin >> file_name;

        fichero.open(file_name);

        read_lines = tablero.read_coord_file(fichero);
        std::cout << "Número de obstaculos añadidos por fichero : " << read_lines << std::endl;
        break;

      case 1:
        float obstacles_percentage = 0;
        bool bool_aleatorio = false;
        int x_coord, y_coord = 0; // i, j
        int total_cells = M * N;
        int obstacles_number = 0;
        std::cout << "¿Quiere que se generen aleatoriamente o introducirlos de forma manual (0 aleatorio, 1 manual)?" << std::endl;
        std::cin >> bool_aleatorio;

        if (!bool_aleatorio){
          std::cout << "¿Cual es el porcenaje de obstaculos que quieres colocar (de 0 a 100)?" << std::endl;
          std::cin >> obstacles_percentage;
          tablero.create_random_obstacle(obstacles_percentage);
        } else {
          std::cout << "¿Cual es el numero de obstaculos que quieres colocar (de 0 a "<< total_cells << " )?" << std::endl;
          std::cin >> obstacles_number;
          for (int i = 1; i <= obstacles_number; i++) {
            std::cout << "Introduzca la coordenada x del obstáculo " << i << ": ";
            std::cin >> x_coord;

            std::cout << "\nIntroduzca la coordenada y del obstáculo " << i << ": ";
            std::cin >> y_coord;

            tablero.create_obstacle(x_coord, y_coord);
          }
        }
        break;
    }
    int moveset = 5;
    while (moveset != 4 && moveset != 8){
      std::cout << "¿Que set de movimientos quieres usar,  4 movimientos, 8 movimientos (4,8)?" << std::endl;
      std::cin >> moveset;
    }
    tablero.set_heuristic(opcion_heuristica);
    //tablero.a_star(X_puntoA, Y_puntoA, X_puntoB, Y_puntoB);
    bool result;
    result = tablero.optimal_path(X_puntoA, Y_puntoA, X_puntoB, Y_puntoB, taxi, moveset);

    bool coord_file = false;
    std::cout << "¿Quieres sacar un fichero de las coordenadas de los obstaculos generados (0 no, 1 si)?" << std::endl;
    std::cin >> coord_file;
    if (coord_file){
      coord_out.open("obs_coord");
      tablero.print_board(taxi, coord_out, 1);
    }


    // Print the board
    if (print_file == true) {
      fichero_out.open("output.txt");
      tablero.print_board(taxi, fichero_out);
    } else {
      tablero.print_board(taxi);
    }
    if (!result) std::cout << std::endl <<"No se ha encontrado camino hasta el punto final" << std::endl;
} 