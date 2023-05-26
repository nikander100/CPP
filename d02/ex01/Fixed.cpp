/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 17:02:27 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/26 17:24:01 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int val) : _value(val << _fractionalBits) {
	std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float val){
	std::cout << "Float constructor called." << std::endl;
	_value = static_cast<int>(roundf(val * (1 << _fractionalBits)));
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
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return (_value);
}

void Fixed::setRawBits(int raw) {
	_value = raw;
}

float Fixed::toFloat() const {
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int Fixed::toInt() const {
	return (_value / (1 <<_fractionalBits));
}
