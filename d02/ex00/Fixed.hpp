/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 17:03:52 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/02/06 18:05:07 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>
# include <cmath>
# include <limits.h>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator = (const Fixed &other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int _value;
	static const int _fractionalBits = 8;

};

#endif
