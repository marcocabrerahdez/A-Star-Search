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
    std::string file_name;
    std::cout << "Practica nº1: Búsqueda";
    std::cout << "Introduzca el tamaño de la matriz (MxN):" << std::endl << "M: ";
    std::cin >> M;
    std::cout << std::endl << "N: ";
    std::cin >> N; 
    Board tablero(M, N);
    std::cout << "¿Quiere introducir los obstáculos por pantalla o cargar un fichero de coordenadas (X,Y)? (0 por fichero, 1 por pantalla)" << std:endl;
    std::cin >> opcion;

    switch (opcion) {
    case 0:
        std::cout "Introduzca el nombre del fichero:" << std:endl;
        std::cin >> file_name;
        std::ifstream fichero(file_name);
        


        break;
    case 1:
        int Num_obstaculos = 0;
        bool bool_aleatorio = false;
        int x_coord, y_coord = 0; //i , j
        std::cout "¿Cuantos obstaculos quiere colocar?" << std:endl;
        std::cin >> Num_obstaculos;
        std::cout "¿Quiere introducirlos aleatoriamente o de forma manual (0 aleatorio, 1 manual)?" << std::endl;
        std::cin >> bool_aleatorio;
        
        if (!bool_aleatorio){
            int number_rows = tablero.getRows();
            int number_cols = tablero.getCols();
            //Llamar a la funcion generar obstaculos aleatorios

        }
        else {
            for (int i = 1; i <= Num_obstaculos; i++){
                std::cout << "Introduzca la coordenada x del obstáculo " << i << ": ";
                std::cin >> x_coord;
                std::cout << /n << "Introduzca la coordenada y del obstáculo " << i << ": ";
                std::cin >> y_coord;
                tablero.createObsatcle(x_coord, y_coord);
            }
        }
        break;
    default:
        std::cout << "Ha introducido una opcion invalida";
        break;
    }
    //mostrar el board por pantalla


}