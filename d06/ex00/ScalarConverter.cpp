/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 17:18:52 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/04 21:53:00 by nvan-der      ########   odam.nl         */
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

void ScalarConverter::convert(const std::string& input) {
	if (isChar(input)) {
		convertFromChar(input);
	} else if (isInt(input)) {
		convertFromInt(input);
	} else if (isFloat(input)) {
		convertFromFloat(input);
	} else if (isDouble(input)) {
		convertFromDouble(input);
	} else if (isPseudo(input)) {
		convertFromPseudo(input);
	} else {
		std::cout << "Invalid input. Enter a char, int, float, or double value." << std::endl;
	}
}

// Checkers 

bool ScalarConverter::isChar(const std::string &input){
	if (input.length() == 1)
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &input) {
	try {
		std::size_t pos;
		std::stoi(input, &pos);
		return pos == input.length();
	} catch (...) {
		return false;
	}
}

bool ScalarConverter::isFloat(const std::string &input) {
	try {
		size_t pos;
		std::stof(input, &pos);
		
		if (pos == input.length() - 1 && input.back() == 'f')
			return true;
		else
			return false;
	} catch (...) {
		return false;
	}
}


bool ScalarConverter::isDouble(const std::string &input) {
	try {
		size_t pos;
		std::stod(input, &pos);
		return pos == input.size(); 
		return true;
	} catch (...) {
		return false;
	}
}

bool	ScalarConverter::isPseudo(const std::string &input)
{
	const std::string	pseudoList[] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };

	for (size_t i = 0; i < (sizeof(pseudoList) / sizeof(pseudoList[0])); i++) {
		if (input == pseudoList[i])
			return true;
	}
	return false;
}

// Converters

void ScalarConverter::convertFromChar(const std::string &input) {
	char	c = input[0];
	
	try {
		std::cout << "  char: \t'" << static_cast<char>(c) << "'" << std::endl;
	} catch (...) {
		std::cout << "  char: \tNon displayable" << std::endl;
	}
	std::cout << "int:    \t" << static_cast<int>(c) << std::endl;
	std::cout << "float:  \t" << std::fixed << std::setprecision(8) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: \t" << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(const std::string &input) {
	int i = std::stoi(input);

	if (i <= std::numeric_limits<char>::min() || i >= std::numeric_limits<char>::max())
		std::cout << "char:   \timpossible" << std::endl;
	else {
		if (std::isprint(i))
			std::cout << "char:   \t'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char:   \tnon displayable" << std::endl;
	}
	std::cout << "int:    \t" << i << std::endl;
	std::cout << "float:  \t" << std::fixed << std::setprecision(8) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: \t" << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string &input) {
	float	f = stof(input);

	if (f <= std::numeric_limits<char>::min() || f >= std::numeric_limits<char>::max())
		std::cout << "char:   \timpossible" << std::endl;
	else {
		if (std::isprint(static_cast<char>(f)))
			std::cout << "char:   \t'" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char:   \tnon displayable" << std::endl;
	}
	if (f <= std::numeric_limits<int>::min() || f >= static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int:    \timpossible" << std::endl;
	else
		std::cout << "int:    \t" << static_cast<int>(f) << std::endl;
	std::cout << "float:  \t" << std::fixed << std::setprecision(8) << f << "f" << std::endl;
	std::cout << "double: \t" << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string &input) {
	double	d = std::stod(input);

	if (d <= std::numeric_limits<char>::min() || d >= std::numeric_limits<char>::max())
		std::cout << "char:   \timpossible" << std::endl;
	else {
		if (std::isprint(static_cast<char>(d)))
			std::cout << "char:   \t'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char:   \tnon displayable" << std::endl;
	}
	if (d <= std::numeric_limits<int>::min() || d >= std::numeric_limits<int>::max())
		std::cout << "int:    \timpossible" << std::endl;
	else
		std::cout << "int:    \t" << static_cast<int>(d) << std::endl;
	std::cout << "float:  \t" << std::fixed << std::setprecision(8) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: \t" << d << std::endl;
}

void ScalarConverter::convertFromPseudo(const std::string &input) {
	std::cout << "char:   \timpossible" << std::endl;
	std::cout << "int:    \timpossible" << std::endl;
	if (input == "-inff" || input == "+inff" || input == "nanf") {
		std::cout << "float:  \t" << input << std::endl;
		std::cout << "double: \t" << input.substr(0, input.size() - 1) << std::endl;
	}
	else {
		std::cout << "float:  \t" << input << "f" << std::endl;
		std::cout << "double: \t" << input << std::endl;
	}
}
