/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverterBak.cpp                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 17:18:52 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/04 18:37:27 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverterBak.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const std::string &input) : _num(false) {
	_num = isNumber(input);
	if (input == "nan" || input == "nanf") {
		_num = true;
		_intVal = std::numeric_limits<double>::quiet_NaN();
	} else if (input == "+inf" || input == "+inff"
			|| input == "-inf" || input == "-inff") {
		_num = true;
		_intVal = std::numeric_limits<double>::infinity();
	} else if (input.length() == 1 && !_num) {
		_intVal = static_cast<double>(input[0]);
	} else if (!input.empty()) {
		try {
			size_t pos = 0;
			_intVal = std::stod(input, &pos);
			if (pos != input.length()) {
				if (input[pos] == 'f') {
					_intVal = static_cast<float>(_intVal);
					pos++;
				} else {
					throw InvalidInputException();
				}
			}
			if (pos != input.length()) {
				throw InvalidInputException();
			}
		} catch (const std::invalid_argument &) {
			throw InvalidInputException();
		} catch (const std::out_of_range &) {
			throw InvalidInputException();
		}
	} else {
		throw InvalidInputException();
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
	double convertedInt = static_cast<double>(*this);

	if (std::isnan(convertedInt) || !(std::numeric_limits<int>::min() <= convertedInt && convertedInt <= std::numeric_limits<int>::max()))
		throw ImpossibleException();
	return static_cast<int>(convertedInt);
}

ScalarConverter::operator char() const {
	int convertedChar = static_cast<int>(*this);

	if (convertedChar <= std::numeric_limits<char>::min() || convertedChar >= std::numeric_limits<char>::max())
		throw ImpossibleException();
	if (std::isprint(convertedChar))
		return static_cast<char>(convertedChar);
	throw NonDisplayableException();
}

ScalarConverter::operator float() const {
	double convertedFloat = static_cast<double>(*this);

	return static_cast<float>(convertedFloat);
}

ScalarConverter::operator double() const {
	return _intVal;
}

bool ScalarConverter::isNumber(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while ((it != s.end() && std::isdigit(*it))) ++it;
	return !s.empty() && it == s.end();
}

// Exceptions

const char* ScalarConverter::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

const char* ScalarConverter::ImpossibleException::what() const throw() {
	return "Impossible";
}

const char* ScalarConverter::InvalidInputException::what() const throw() {
	return "Invalid input";
}

std::ostream &operator<<(std::ostream &out, ScalarConverter const &rhs) {
	try {
		out << "  char: ";
		out << static_cast<char>(rhs);
	} catch (const std::exception &e) {
		out << e.what();
	}
	out << std::endl;
	try {
		out << "   int: ";
		out << static_cast<int>(rhs);
	} catch (const std::exception &e) {
		out << e.what();
	}
	out << std::endl;
	try {
		out << " float: ";
		out << static_cast<float>(rhs);
	} catch (const std::exception &e) {
		out << e.what();
	}
	out << "f" << std::endl;
	try {
		out << "double: ";
		out << static_cast<double>(rhs);
	} catch (const std::exception &e) {
		out << e.what();
	}
	out << std::endl;
	return out;
}
