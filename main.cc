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

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"

#define std::string FREE "."
#define std::string OBSTACULO ""


int main (){
    
    int M = 0; //filas
    int N = 0; //columnas
    int opcion = 0;
    int X_puntoA, X_puntoB = 0;
    int Y_puntoB, X_puntoB = 0;
    std::string file_name;
    std::cout << "Practica nº1: Búsqueda";
    std::cout << "Introduzca el tamaño de la matriz (MxN):" << std::endl << "M: ";
    std::cin >> M;
    std::cout << std::endl << "N: ";
    std::cin >> N; 
    Board tablero(M, N);
    std::cout << "Indique el punto inicial (x): ";
    std::cin >> X_puntoA;
    std::cout << /n << "/nIndique el punto inicial (y): ";
    std::cin >> Y_puntoA;
    std::cout << "Indique el punto final (x): ";
    std::cin >> X_puntoB;
    std::cout << /n << "/nIndique el punto final (y) ";
    std::cin >> Y_puntoB;
    //Accion a realizar con estos puntos, colocar el taxi en el punto A
    std::cout << "¿Quiere introducir los obstáculos por pantalla o cargar un fichero de coordenadas (X,Y)? (0 por fichero, 1 por pantalla)" << std:endl;
    std::cin >> opcion;

    switch (opcion) {
    case 0:
        std::cout "Introduzca el nombre del fichero:" << std::endl;
        std::cin >> file_name;
        std::ifstream fichero(file_name);
        


        break;
    case 1:
        int num_obstaculos = 0;
        bool bool_aleatorio = false;
        int x_coord, y_coord = 0; //i , j
        int total_cells = (M*N);

        /* 2 posibilidades:

            Numero concreto de obstaculos con sus coordenadas manualmente
            Numero concreto de obstaculos con sus generacion aleatoria
            
       */
        std::cout "¿Cuantos obstaculos quiere colocar (de 0 a " << total_cells << " )?" << std::endl;
        std::cin >> Num_obstaculos;
        std::cout "¿Quiere introducirlos aleatoriamente o de forma manual (0 aleatorio, 1 manual)?" << std::endl;
        std::cin >> bool_aleatorio;
        
        if (!bool_aleatorio){
            int number_rows = tablero.getRows(); //M
            int number_cols = tablero.getCols(); //N
            tablero.createRandomObstacle(num_obstaculos);
        }
        else {
            for (int i = 1; i <= num_obstaculos; i++){
                std::cout << "Introduzca la coordenada x del obstáculo " << i << ": ";
                std::cin >> x_coord;
                std::cout << /n << "Introduzca la coordenada y del obstáculo " << i << ": ";
                std::cin >> y_coord;
                tablero.createObstacle(x_coord, y_coord);
            }
        }
        break;
    default:
        std::cout << "Ha introducido una opcion invalida";
        break;
    }
    

    tablero.printBoard();


}