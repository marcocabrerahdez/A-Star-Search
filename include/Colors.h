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
    std::string write_grey(const std::string& myString);
    std::string write_red(const std::string& myString);
    std::string write_green(const std::string& myString);
    std::string write_yellow(const std::string& myString);
    std::string write_blue(const std::string& myString);
    std::string write_magenta(const std::string& myString);
    std::string write_cyan(const std::string& myString);
    std::string write_white(const std::string& myString);
};

#endif // COLORS_H_