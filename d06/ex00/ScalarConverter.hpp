/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 17:18:55 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/03 21:18:26 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <cctype>
#include <limits>

class ScalarConverter {
public:
	virtual ~ScalarConverter();

	static void convert(const std::string &input);

	class NonDisplayableException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class ImpossibleException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class InvalidInputException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
private:
	ScalarConverter();
	ScalarConverter(const std::string &input);
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &rhs);

	static bool isChar(const std::string &input);
	static bool isInt(const std::string &input);
	static bool isFloat(const std::string &input);
	static bool isDouble(const std::string &input);
	static bool isSpecial(const std::string &input);

	static void	convertToChar(const std::string &input);
	static void	convertToInt(const std::string &input);
	static void	convertToFloat(const std::string &input);
	static void	convertToDouble(const std::string &input);
	static void	convertToPseudo(const std::string &input);

};