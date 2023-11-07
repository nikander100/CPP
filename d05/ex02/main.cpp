/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/07 19:31:37 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

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
	srand(time(NULL));
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
	Bureaucrat jim("Jim", 45);
	Bureaucrat jane("Jane", 137);

	std::cout << john << std::endl;
	std::cout << jim << std::endl;
	std::cout << jane << std::endl;

	ShrubberyCreationForm shrubbery("home");
	PresidentialPardonForm pardon("Stephen Bannon");
	RobotomyRequestForm robotomy("Bender");

	john.executeForm(shrubbery);
	jim.executeForm(shrubbery);
	jane.executeForm(shrubbery);
	std::cout << std::endl;
	john.signForm(shrubbery);
	jim.signForm(shrubbery);
	jane.signForm(shrubbery);
	std::cout << std::endl;
	john.executeForm(shrubbery);
	jim.executeForm(shrubbery);
	jane.executeForm(shrubbery);
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	john.executeForm(pardon);
	jim.executeForm(pardon);
	jane.executeForm(pardon);
	std::cout << std::endl;
	john.signForm(pardon);
	jim.signForm(pardon);
	jane.signForm(pardon);
	std::cout << std::endl;
	john.executeForm(pardon);
	jim.executeForm(pardon);
	jane.executeForm(pardon);
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	john.executeForm(robotomy);
	jim.executeForm(robotomy);
	jane.executeForm(robotomy);
	std::cout << std::endl;
	john.signForm(robotomy);
	jim.signForm(robotomy);
	jane.signForm(robotomy);
	std::cout << std::endl;
	john.executeForm(robotomy);
	jim.executeForm(robotomy);
	jane.executeForm(robotomy);
}
