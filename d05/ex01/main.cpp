/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/02 19:57:35 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Bureaucrat john("John", 5);


	std::cout << john << std::endl;
	toContinue();

	try {
		john.incrementGrade();
		john.incrementGrade();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	toContinue();
	try {
		Form test("test", 151, 42);
	}
	catch(const std::exception& e) {
		std::cerr << "Cannot initialize test: " << e.what() << std::endl;
	}

	toContinue();
	Form a("a");
	Form b("b", 3, 3);
	Form c("c", 3, 20);
	std::cout << john << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	toContinue();
	john.signForm(a);
	john.signForm(b);
	john.signForm(b);
	
	toContinue();
	try {
		john.decrementGrade();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	toContinue();
	john.signForm(c);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}
