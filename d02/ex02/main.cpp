/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/06/02 19:18:33 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"

static void toContinue(void) {
	std::cout << TEAL << "\nPress ENTER to continue...\n" << RESET;
	std::getchar();
}

int main(int argc, char **argv) {
	if (argc > 1) {
		std::string arg = argv[1];
		if (arg == "DEBUG=false") {
			std::cout << BRIGHTRED <<"[INFO] " << RESET << "DEBUG == false";
			debug = false;
		}
	}
	else {
		std::cout << BRIGHTRED <<"[INFO] " << RESET << "Run using `" << TEAL 
			<<"./runme DEBUG=false" << RESET <<"` to disable constructor/destructor messages.";
	}
	toContinue();

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	toContinue();
	std::cout << "[MORE TESTS]" << std::endl << std::endl;

	std::cout << "raw: " << a.getRawBits() << " " << b.getRawBits() << std::endl;

	toContinue();
	std::cout << "10.1016f / 2 =	" << Fixed( 10.1016f ) / Fixed( 2 ) << std::endl;
	std::cout << "5.05f * 2 =	" << Fixed(5.05f) * Fixed(2) << std::endl;
	std::cout << "5.05f + 2 =	" << Fixed(5.05f) + Fixed(2) << std::endl;
	std::cout << "5.05f - 2 =	" << Fixed(5.05f) - Fixed (2) << std::endl;

	toContinue();
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	toContinue();
	std::cout << "Division by 0" << std::endl;
	std::cout << "10.1016f / 0 =	" << Fixed(10.1016f) / Fixed(0) << std::endl;
	std::cout << "multiplication by 0" << std::endl;
	std::cout << "10.1016f * 0 =	" << Fixed(10.1016f) * Fixed(0) << std::endl;

	return (0);
}
