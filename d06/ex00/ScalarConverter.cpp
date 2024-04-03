/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 17:18:52 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/03 21:17:25 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {
}

// bool ScalarConverter::isNumber(const std::string& s) {
// 	std::string::const_iterator it = s.begin();
// 	while ((it != s.end() && std::isdigit(*it))) ++it;
// 	return !s.empty() && it == s.end();
// }

void ScalarConverter::convert(const std::string& input) {
	if (isChar(input)) {
		convertToChar(input);
	} else if (isInt(input)) {
		convertToInt(input);
	} else if (isFloat(input)) {
		convertToFloat(input);
	} else if (isDouble(input)) {
		convertToDouble(input);
	} else if (isSpecial(input)) {
		convertToPseudo(input);
	} else {
		std::cout << "Invalid input. Enter a char, int, float, or double value." << std::endl;
	}
}

// Exceptions

const char* ScalarConverter::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

const char* ScalarConverter::ImpossibleException::what() const throw() {
	return "impossible";
}

const char* ScalarConverter::InvalidInputException::what() const throw() {
	return "Invalid input";
}


// Checkers 

bool ScalarConverter::isChar(const std::string &input) {
	return input.length() == 1;
}

bool ScalarConverter::isInt(const std::string &input) {
	try {
		std::stoi(input);
		return true;
	} catch (...) {
		return false;
	}
}

bool ScalarConverter::isFloat(const std::string &input) {
	try {
		std::stof(input);
		return true;
	} catch (...) {
		return false;
	}
}

bool ScalarConverter::isDouble(const std::string &input) {
	try {
		std::stod(input);
		return true;
	} catch (...) {
		return false;
	}
}