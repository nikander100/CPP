/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 17:03:52 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/26 17:19:55 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>
# include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &copy);
	Fixed &operator = (const Fixed &other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int raw);
	float toFloat() const;
	int toInt() const;


private:
	int _value;
	static const int _fractionalBits = 8;

};
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
