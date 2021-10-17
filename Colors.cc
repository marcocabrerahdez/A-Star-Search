#include "Colors.h"

/**
 * @brief      Writes the given text with grey color.
 *
 * @param[in]  str  My string
 *
 * @return     The string written with the color.
 */
std::string Colors::writeGrey(const std::string& str) {
	return ("\033[30m" + str + "\033[00m");
}



/**
 * @brief      Writes the given text with red color.
 *
 * @param[in]  str  My string
 *
 * @return     The string written with the color.
 */
std::string Colors::writeRed(const std::string& str) {
	return ("\033[31m" + str + "\033[00m");
}



/**
 * @brief      Writes the given text with green color.
 *
 * @param[in]  str  My string
 *
 * @return     The string written with the color.
 */
std::string Colors::writeGreen(const std::string& str) {
	return ("\033[32m" + str + "\033[00m");
}



/**
 * @brief      Writes the given text inn color yellow.
 *
 * @param[in]  str  My string
 *
 * @return     The string written with the color.
 */
std::string Colors::writeYellow(const std::string& str) {
	return ("\033[33m" + str + "\033[00m");
}



/**
 * @brief      Writes the given text with blue color.
 *
 * @param[in]  str  My string
 *
 * @return     The string written with the color.
 */
std::string Colors::writeBlue(const std::string& str) {
	return ("\033[34m" + str + "\033[00m");
}



/**
 * @brief      Writes the given text with magenta color.
 *
 * @param[in]  str  My string
 *
 * @return     The string written with the color.
 */
std::string Colors::writeMagenta(const std::string& str) {
	return ("\033[35m" + str + "\033[00m");
}



/**
 * @brief      Paints the given text with cyan color.
 *
 * @param[in]  str  My string
 *
 * @return     The string written with the color.
 */
std::string Colors::writeCyan(const std::string& str) {
	return ("\033[36m" + str + "\033[00m");
}



/**
 * @brief      Paints the given text with white color.
 *
 * @param[in]  str  My string
 *
 * @return     The string written with the color.
 */
std::string Colors::writeWhite(const std::string& str) {
	return ("\033[37m" + str + "\033[00m");
}