/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 15:48:40 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/06/08 18:39:02 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	// Calculate vectors
	Fixed v0x = c.getX() - a.getX(); // Vector from vertex a to vertex c.
	Fixed v0y = c.getY() - a.getY();
	Fixed v1x = b.getX() - a.getX(); // Vector from vertex a to vertex b.
	Fixed v1y = b.getY() - a.getY();
	Fixed v2x = point.getX() - a.getX(); // Vector from vertex a to the given point
	Fixed v2y = point.getY() - a.getY();

	// Compute dot products
	Fixed dot00 = v0x * v0x + v0y * v0y; //squared length of edge0 (v0)
	Fixed dot01 = v0x * v1x + v0y * v1y; //projection of edge1 (v1) onto edge0 (v0)
	Fixed dot02 = v0x * v2x + v0y * v2y; //projection of point (v2) onto edge0 (v0)
	Fixed dot11 = v1x * v1x + v1y * v1y; //squared length of edge1 (v1)
	Fixed dot12 = v1x * v2x + v1y * v2y; //projection of point (v2) onto edge1 (v1)

	// Compute barycentric coordinates
	// "invDenom" stands for inverse denominator.
	// It is calculated as the reciprocal of the denominator,
	// in the formula used to compute the barycentric coordinates u and v
	
	Fixed invDenom = Fixed(1) / (dot00 * dot11 - dot01 * dot01);
	Fixed u = (dot11 * dot02 - dot01 * dot12) * invDenom; //represents weigth of a to point
	Fixed v = (dot00 * dot12 - dot01 * dot02) * invDenom; //represents weigth of b to point
	Fixed w = Fixed(1) - u - v; //represents weigth of b to point
	//The remaining weight (1-u-v) represents the contribution of c to point within the triangle. If the weight is negative point is outside of the triangle.

	// Check if point is inside triangle
	return (u >= Fixed(0)) && (v >= Fixed(0)) && (w >= Fixed(0));
}

