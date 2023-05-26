/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 17:02:27 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/26 16:15:03 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& fix) : _value(fix._value) {
	std::cout << "Copy Constructor called." << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called: ";
	if (this != &other) {
		std::cout << "Pass." << std::endl;
		_value = other._value;
	} else
		std::cout << "Fail." << std::endl;
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return (_value);
}

void Fixed::setRawBits(int raw) {
	_value = raw;
}
