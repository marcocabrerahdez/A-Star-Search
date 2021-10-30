/**
 * University of La Laguna
 * Subject: Artificial Intelligence
 * Practice # 1: Search.
 * @author Marco Antonio Cabrera Hernández
 * @author Jose Antonio Trujillo Mendoza
 * @author Mario Hernández García
 * @class Color
 * @brief Returns a color for each element of the game
 *
 *
 * @date 02/11/2021
*/
#ifndef COLORS_H_
#define COLORS_H_

#include <iostream>
#include <string>

class Colors {
  public:
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