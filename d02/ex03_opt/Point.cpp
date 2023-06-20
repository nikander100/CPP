/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 15:39:09 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/06/08 18:41:53 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {}

Point::~Point() {}

Point &Point::operator=(const Point& right) {
	if (this != &right) {
		_x = right.getX();
		_y = right.getY();
	}
	return *this;
}

Fixed Point::getX() const{
	return (_x);
}

Fixed Point::getY() const{
	return (_y);
}
