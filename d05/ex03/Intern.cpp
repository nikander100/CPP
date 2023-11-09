/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 20:08:11 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/09 20:39:52 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

const char *Intern::InvalidFormNameException::what() const throw() {
	return ("Invalid form type");
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const {
	AForm *form = nullptr;
	std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (size_t i = 0; i < 3; i++) {
		if (formNames[i] == name && i < formNames->length()) {
			switch (i) {
				case 0:
					form = new PresidentialPardonForm(target);
					break;
				case 1:
					form = new RobotomyRequestForm(target);
					break;
				case 2:
					form = new ShrubberyCreationForm(target);
					break;
				default:
					std::cout << "This should never happen" << std::endl;
					throw Intern::InvalidFormNameException();
			}
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	throw Intern::InvalidFormNameException();
}