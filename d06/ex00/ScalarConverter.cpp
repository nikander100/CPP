/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 17:18:52 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/21 20:10:48 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const std::string &input) : _num(false) {
	_num = isNumber(input);
	if (input == "nan" || input == "nanf"
		|| input == "+inf" || input == "+inff"
		|| input == "-inf" || input == "-inff")
		_num = true;
	if (!_num) {
		if (!input.empty()) {
			_intVal = static_cast<double>(input[0]);
		} else {
			throw InvalidInputException();
		}
	} else {
		_intVal = std::stod(input);
	}
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	if (this != &rhs) {
		_num = rhs._num;
		_intVal = rhs._intVal;
	}
	return *this;
}

ScalarConverter::operator int() const {
	double converted = static_cast<double>(*this);

	if (std::isnan(converted) || !(std::numeric_limits<int>::min() <= converted && converted <= std::numeric_limits<int>::max()))
		throw ImpossibleException();
	return static_cast<int>(converted);
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

static bool isNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}