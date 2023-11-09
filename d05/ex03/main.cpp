/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/08 20:40:54 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

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
	
	toContinue();

	Bureaucrat diluc("Diluc", 5);
	Bureaucrat zhongli("Zhongli", 45);
	Bureaucrat keqing("Keqing", 137);

	std::cout << BLUE << "[INFO] " << RESET << "Created bureaucrats:" << std::endl;
	std::cout << diluc << std::endl;
	std::cout << zhongli << std::endl;
	std::cout << keqing << std::endl;

	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Creating Intern and empty Forms" << std::endl;

	Intern intern;

	AForm* formA;
	AForm* formB;
	AForm* formC;
	AForm* formD;

	std::cout << BLUE << "[INFO] " << RESET << "Trying to create forms:" << std::endl;
	try
	{
		formA = intern.makeForm("shrubbery creation", "home");
		formB = intern.makeForm("robotomy request", "Bender");
		formC = intern.makeForm("presidential pardon", "Stephen Bannon");
		formD = intern.makeForm("test", "test");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Executing form A:" << std::endl;
	diluc.executeForm(*formA);
	zhongli.executeForm(*formA);
	keqing.executeForm(*formA);
	
	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Signing form A:" << std::endl;
	diluc.signForm(*formA);
	zhongli.signForm(*formA);
	keqing.signForm(*formA);
	
	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Executing form A again:" << std::endl;
	diluc.executeForm(*formA);
	zhongli.executeForm(*formA);
	keqing.executeForm(*formA);
	

	std::cout << std::endl << "-------------------------------------------------------" << std::endl;

	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Executing form B:" << std::endl;
	diluc.executeForm(*formB);
	zhongli.executeForm(*formB);
	keqing.executeForm(*formB);
	
	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Signing form B:" << std::endl;
	diluc.signForm(*formB);
	zhongli.signForm(*formB);
	keqing.signForm(*formB);
	
	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Executing form B again:" << std::endl;
	diluc.executeForm(*formB);
	zhongli.executeForm(*formB);
	keqing.executeForm(*formB);
	std::cout << std::endl << "-------------------------------------------------------" << std::endl;

	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Executing form C:" << std::endl;
	diluc.executeForm(*formC);
	zhongli.executeForm(*formC);
	keqing.executeForm(*formC);

	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Signing form C:" << std::endl;
	diluc.signForm(*formC);
	zhongli.signForm(*formC);
	keqing.signForm(*formC);

	toContinue();
	std::cout << BLUE << "[INFO] " << RESET << "Executing form C again:" << std::endl;
	diluc.executeForm(*formC);
	zhongli.executeForm(*formC);
	keqing.executeForm(*formC);
}
