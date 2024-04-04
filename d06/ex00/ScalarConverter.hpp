/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 17:18:55 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/04 21:32:13 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <cmath>
#include <cctype>
#include <limits>

class ScalarConverter {
public:
	virtual ~ScalarConverter();

	static void convert(const std::string &input);
	
private:
	ScalarConverter();
	ScalarConverter(const std::string &input);
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &rhs);

	static bool isChar(const std::string &input);
	static bool isInt(const std::string &input);
	static bool isFloat(const std::string &input);
	static bool isDouble(const std::string &input);
	static bool isPseudo(const std::string &input);

	static void	convertFromChar(const std::string &input);
	static void	convertFromInt(const std::string &input);
	static void	convertFromFloat(const std::string &input);
	static void	convertFromDouble(const std::string &input);
	static void	convertFromPseudo(const std::string &input);

};