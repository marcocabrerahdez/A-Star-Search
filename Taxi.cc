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
#include "Taxi.h"

Taxi::Taxi(const int& x, const int& y) {
    position_.xCoord = x;
    position_.yCoord = y;
    direction_ = EAST;
}