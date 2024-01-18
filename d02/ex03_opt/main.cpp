/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/01/18 17:46:25 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"
#define BLUE "\033[1;34m"


static void toContinue(void) {
	std::cout << TEAL << "\nPress ENTER to continue...\n" << RESET;
	std::getwchar();
}

int setRandomPoint(int randomFactor)
{
	int	point = 0;
	srand(time(0));

	point = rand() %randomFactor;
	return(point);
}

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(int argc, char **argv) {
	if (argc > 1) {
		std::string arg = argv[1];
		if (arg == "DEBUG=true") {
			std::cout << BRIGHTRED <<"[INFO] " << RESET << "DEBUG == true";
			debug = true;
		}
	}
	else {
		std::cout << BRIGHTRED <<"[INFO] " << RESET << "Run using `" << TEAL 
			<<"./runme DEBUG=true" << RESET <<"` to enable constructor/destructor messages.";
	}
	toContinue();

	Point a(0,0);
	Point b(10, 0);
	Point c(5, 7);

	int x = setRandomPoint(2);
	int y = setRandomPoint(5);

	std::cout << BRIGHTRED <<"[INFO] " << RESET << "Triangle vertices at pos: " 
		<< RED << "a(0, 0) " 
		<< GREEN << "b(10, 0) " 
		<< BLUE << "c(5, 7)" << RESET << std::endl;

	toContinue();
	//test 1
	Point	rdm(x, y);

	std::cout << BRIGHTRED <<"[INFO] " << RESET << "point  " << TEAL << "(" << x << ", " << y << ")"<< RESET <<": ";
	std::cout << (bool)bsp(a, b, c, rdm) << std::endl;

	toContinue();
	//test 2
	Point	d(5, 2);
	Point	e(-1, 1);

	std::cout << "point (5, 2) : " << (int)bsp(a, b, c, d) << std::endl;
	std::cout << "point (-1, 1) : " << (int)bsp(a, b, c, e) << std::endl; 
	return (0);
}
