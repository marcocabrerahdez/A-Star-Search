#include "Colors.h"

std::string Colors::writeGrey(const std::string& str) {
	return ("\033[30m" + str + "\033[00m");
}



std::string Colors::writeRed(const std::string& str) {
	return ("\033[31m" + str + "\033[00m");
}



std::string Colors::writeGreen(const std::string& str) {
	return ("\033[32m" + str + "\033[00m");
}



std::string Colors::writeYellow(const std::string& str) {
	return ("\033[33m" + str + "\033[00m");
}



std::string Colors::writeBlue(const std::string& str) {
	return ("\033[34m" + str + "\033[00m");
}



std::string Colors::writeMagenta(const std::string& str) {
	return ("\033[35m" + str + "\033[00m");
}



std::string Colors::writeCyan(const std::string& str) {
	return ("\033[36m" + str + "\033[00m");
}



std::string Colors::writeWhite(const std::string& str) {
	return ("\033[37m" + str + "\033[00m");
}