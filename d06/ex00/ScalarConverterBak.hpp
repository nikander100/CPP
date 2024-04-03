/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 17:18:55 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/03 19:52:48 by nvan-der      ########   odam.nl         */
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
	ScalarConverter(const std::string &input);
	ScalarConverter(const ScalarConverter &copy);
	virtual ~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &rhs);
	operator int() const;
	operator char() const;
	operator float() const;
	operator double() const;

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
	bool isNumber(const std::string &input);
	bool _num;
	double _intVal;
	ScalarConverter();
};

std::ostream &operator<<(std::ostream &out, ScalarConverter const &rhs);