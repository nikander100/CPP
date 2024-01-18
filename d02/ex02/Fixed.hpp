/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 17:03:52 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/01/18 17:49:40 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

extern bool debug;

# include <iostream>
# include <cmath>
# include <limits.h>

class Fixed {
public:
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &copy);
	~Fixed();

	// Assignment Operator
	Fixed &operator = (const Fixed &right);

	// Comparison Operators
	bool operator > (const Fixed &right) const;
	bool operator < (const Fixed &right) const;
	bool operator >= (const Fixed &right) const;
	bool operator <= (const Fixed &right) const;
	bool operator == (const Fixed &right) const;
	bool operator != (const Fixed &right) const;

	// Arithmetic Operators
	Fixed operator + (const Fixed &right) const;
	Fixed operator - (const Fixed &right) const;
	Fixed operator * (const Fixed &right) const;
	Fixed operator / (const Fixed &right) const;

	// Increment/Decrement Operators
	Fixed &operator ++ (); // Pre-increment
	Fixed operator ++ (int); // Post-increment
	Fixed &operator -- (); // Pre-decrement
	Fixed operator -- (int); // Post-decrement

	int getRawBits() const;
	void setRawBits(int raw);

	float toFloat() const;
	int toInt() const;
	
	static const Fixed &min(Fixed &left, Fixed &right);
	static const Fixed &min(const Fixed &left, const Fixed &right);
	static const Fixed &max(Fixed &left, Fixed &right);
	static const Fixed &max(const Fixed &left, const Fixed &right);

private:
	int _value;
	static const int _fractionalBits = 8;

};
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
