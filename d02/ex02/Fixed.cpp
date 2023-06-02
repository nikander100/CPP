/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 17:02:27 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/06/02 19:21:08 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
bool debug = true;

Fixed::Fixed() : _value(0) {
	if (debug)
		std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int val) : _value(val << _fractionalBits) {
	if (debug)
		std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float val){
	if (debug)
		std::cout << "Float constructor called." << std::endl;
	_value = static_cast<int>(roundf(val * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& fix) : _value(fix._value) {
	if (debug)
		std::cout << "Copy Constructor called." << std::endl;
}

Fixed::~Fixed() {}

// Assignment Operator
Fixed &Fixed::operator=(const Fixed &right) {
	if (debug)
		std::cout << "Copy assignment operator called: ";
	if (this != &right) {
		if (debug)
			std::cout << "Pass." << std::endl;
		_value = right.getRawBits();
	} else
		if (debug)
			std::cout << "Fail." << std::endl;
	return (*this);
}

// Comparison Operators
bool Fixed::operator>(const Fixed &right) const {
	return (_value > right.getRawBits());
}

bool Fixed::operator<(const Fixed &right) const {
	return (_value < right.getRawBits());
}

bool Fixed::operator>=(const Fixed &right) const {
	return (_value >= right.getRawBits());
}

bool Fixed::operator<=(const Fixed &right) const {
	return (_value <= right.getRawBits());
}

bool Fixed::operator==(const Fixed &right) const {
	return (_value == right.getRawBits());
}

bool Fixed::operator!=(const Fixed &right) const {
	return (_value != right.getRawBits());
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &right) const {
	Fixed sum;
	sum.setRawBits(_value + right.getRawBits());
	return (sum);
}

Fixed Fixed::operator-(const Fixed &right) const {
	Fixed sub;
	sub.setRawBits(_value - right.getRawBits());
	return sub;
}

Fixed Fixed::operator*(const Fixed &right) const {
	Fixed product;
	product.setRawBits((_value * right.getRawBits()) >> _fractionalBits);
	return product;
}

Fixed Fixed::operator/(const Fixed &right) const {
	Fixed quotient;
	if (right.getRawBits() == 0) {
		std::cout << "Warning: Division by zero!" << std::endl;
		quotient.setRawBits(((_value < 0) ? INT_MIN : INT_MAX));
		return quotient; // Return +inf or -inf
	}
	quotient.setRawBits((_value << _fractionalBits) / right.getRawBits());
	return quotient;
}

// Increment/Decrement Operators
Fixed &Fixed::operator++() {
	_value++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed &Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return (temp);
}

// Stream operator(s)
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}

const Fixed &Fixed::min(Fixed &left, Fixed &right) {
	return (left < right) ? left : right;
}

const Fixed &Fixed::min(const Fixed &left, const Fixed &right) {
	return (left < right) ? left : right;
}

const Fixed &Fixed::max(Fixed &left, Fixed &right) {
	return (left > right) ? left : right;
}

const Fixed &Fixed::max(const Fixed &left, const Fixed &right) {
	return (left > right) ? left : right;
}

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
	return (_value >> _fractionalBits);
}
