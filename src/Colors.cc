#include "../include/Colors.h"

std::string Colors::write_grey(const std::string& str) {
	return ("\033[30m" + str + "\033[00m");
}



std::string Colors::write_red(const std::string& str) {
	return ("\033[31m" + str + "\033[00m");
}



std::string Colors::write_green(const std::string& str) {
	return ("\033[32m" + str + "\033[00m");
}



std::string Colors::write_yellow(const std::string& str) {
	return ("\033[33m" + str + "\033[00m");
}



std::string Colors::write_blue(const std::string& str) {
	return ("\033[34m" + str + "\033[00m");
}



std::string Colors::write_magenta(const std::string& str) {
	return ("\033[35m" + str + "\033[00m");
}



std::string Colors::write_cyan(const std::string& str) {
	return ("\033[36m" + str + "\033[00m");
}



std::string Colors::write_white(const std::string& str) {
	return ("\033[37m" + str + "\033[00m");
}