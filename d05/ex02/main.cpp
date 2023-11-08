/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/08 19:18:10 by nvan-der      ########   odam.nl         */
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
	std::cout << BLUE << "[INFO]: " << RESET << "Bureaucrats:" << std::endl;
	Bureaucrat klee("Klee", 5);
	Bureaucrat hutao("Hu Tao", 45);
	Bureaucrat paimon("Paimon", 137);

	std::cout << klee;
	std::cout << hutao;
	std::cout << paimon;

	ShrubberyCreationForm shrubbery("home");
	PresidentialPardonForm pardon("Stephen Bannon");
	RobotomyRequestForm robotomy("Bender");

	toContinue();
	std::cout << BLUE << "[INFO]: " << RESET << "Executing ShrubberyCreationForm:" << std::endl;
	klee.executeForm(shrubbery);
	hutao.executeForm(shrubbery);
	paimon.executeForm(shrubbery);
	toContinue();
	std::cout << BLUE << "[INFO]: " << RESET << "Signing ShrubberyCreationForm:" << std::endl;
	klee.signForm(shrubbery);
	hutao.signForm(shrubbery);
	paimon.signForm(shrubbery);
	toContinue();
	std::cout << BLUE << "[INFO]: " << RESET << "Executing ShrubberyCreationForm again:" << std::endl;
	klee.executeForm(shrubbery);
	hutao.executeForm(shrubbery);
	paimon.executeForm(shrubbery);

	std::cout << std::endl << "-------------------------------------------------------" << std::endl;

	toContinue();
	std::cout << BLUE << "[INFO]: " << RESET << "Executing PresidentialPardonForm:" << std::endl;
	klee.executeForm(pardon);
	hutao.executeForm(pardon);
	paimon.executeForm(pardon);
	toContinue();
	std::cout << BLUE << "[INFO]: " << RESET << "Signing PresidentialPardonForm:" << std::endl;
	klee.signForm(pardon);
	hutao.signForm(pardon);
	paimon.signForm(pardon);
	toContinue();
	std::cout << BLUE << "[INFO]: " << RESET << "Executing PresidentialPardonForm again:" << std::endl;
	klee.executeForm(pardon);
	hutao.executeForm(pardon);
	paimon.executeForm(pardon);

	std::cout << std::endl << "-------------------------------------------------------" << std::endl;

	toContinue();
	std::cout << BLUE << "[INFO]: " << RESET << "Executing RobotomyRequestForm:" << std::endl;
	klee.executeForm(robotomy);
	hutao.executeForm(robotomy);
	paimon.executeForm(robotomy);
	toContinue();
	std::cout << BLUE << "[INFO]: " << RESET << "Signing RobotomyRequestForm:" << std::endl;
	klee.signForm(robotomy);
	hutao.signForm(robotomy);
	paimon.signForm(robotomy);
	toContinue();
	std::cout << BLUE << "[INFO]: " << RESET << "Executing RobotomyRequestForm again:" << std::endl;
	klee.executeForm(robotomy);
	hutao.executeForm(robotomy);
	paimon.executeForm(robotomy);
}
