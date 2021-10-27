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
#ifndef COLORS_H_
#define COLORS_H_

#include <iostream>
#include <string>

class Colors {
  public:
    // Builder & Destroyer
    Colors(void) = default;

    // Text color functions
    std::string writeGrey(const std::string& myString);
    std::string writeRed(const std::string& myString);
    std::string writeGreen(const std::string& myString);
    std::string writeYellow(const std::string& myString);
    std::string writeBlue(const std::string& myString);
    std::string writeMagenta(const std::string& myString);
    std::string writeCyan(const std::string& myString);
    std::string writeWhite(const std::string& myString);
};

#endif // COLORS_H_