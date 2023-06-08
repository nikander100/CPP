/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 15:39:11 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/06/08 18:39:42 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &copy);
	~Point();

	// Assignment Operator
	Point &operator = (const Point &right);
	Fixed getX() const;
	Fixed getY() const;

private:
Fixed _x, _y;

};

#endif
