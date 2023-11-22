/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/22 20:09:34 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

// bool debug = false;

// #define RESET "\033[0m"
// #define GREEN "\033[1;32m"
// #define YELLOW "\033[1;33m"
// #define RED "\033[1;31m"
// #define BRIGHTRED "\033[31m"
// #define TEAL "\033[36m"
// #define BLUE "\033[1;34m"


// static void toContinue(void) {
// 	std::cout << TEAL << "\nPress ENTER to continue...\n" << RESET;
// 	std::getchar();
// }

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert [input]" << std::endl;
		return 1;
	}
	try {
		ScalarConverter scalar(av[1]);
		std::cout << scalar;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}