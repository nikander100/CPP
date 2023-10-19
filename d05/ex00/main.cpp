/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/10/19 17:46:00 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

bool debug = false;

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"
#define BLUE "\033[1;34m"


static void toContinue(void) {
	std::cout << TEAL << "\nPress ENTER to continue...\n" << RESET;
	std::getchar();
}

int main() {
	// if (argc > 1) {
	// 	std::string arg = argv[1];
	// 	if (arg == "DEBUG=true") {
	// 		std::cout << BRIGHTRED <<"[INFO] " << RESET << "DEBUG == true";
	// 		debug = true;
	// 	}
	// }
	// else {
	// 	std::cout << BRIGHTRED <<"[INFO] " << RESET << "DEBUG == False" << std::endl;
	// 	std::cout << BRIGHTRED <<"[INFO] " << RESET << "Run using `" << TEAL 
	// 		<<"./runme DEBUG=true" << RESET <<"` to enable constructor/destructor messages.";
	// }
	
	toContinue();

	Bureaucrat klee("klee", 2);
	Bureaucrat kokofish("kokofish", 149);

	try {
		std::cout << BLUE << "[INFO] " << RESET << "Printing klee and kokofish" << std::endl;
		std::cout << klee;
		std::cout << kokofish;
		toContinue();
		std::cout << BLUE << "[INFO] " << RESET << "Incrementing klee and decrementing kokofish" << std::endl;
		klee.incrementGrade();
		kokofish.decrementGrade();
		std::cout << klee;
		std::cout << kokofish;
		toContinue();
		std::cout << BLUE << "[INFO] " << RESET << "Incrementing klee and decrementing kokofish" << std::endl;
		klee.incrementGrade();
		kokofish.decrementGrade();
		std::cout << klee;
		std::cout << kokofish;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
