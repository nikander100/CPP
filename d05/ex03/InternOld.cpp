/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   InternOld.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 20:08:11 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/02 21:38:41 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() : _formNames{"presidential pardon", "robotomy request", "shrubbery creation"} {}


Intern::~Intern() {
}

const char *Intern::InvalidFormNameException::what() const throw() {
	return ("Invalid form type");
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const {
	AForm *form = nullptr;
	for (size_t i = 0; i < 3; i++) {
		if (_formNames[i] == name && i < _formNames->length()) {
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