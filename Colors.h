#pragma once 

#include <iostream>

/**
 * @brief This class describes a colorizer.
 */
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