/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/01/18 17:49:21 by nvan-der      ########   odam.nl         */
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

static void toContinue(void)
{
	std::cout << TEAL << "\nPress ENTER to continue...\n"
			  << RESET;
	std::getwchar();
}

int main()
{

	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	toContinue();

	a = Fixed(1234.4321f);
	toContinue();

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	toContinue();

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
