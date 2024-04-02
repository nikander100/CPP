/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 20:08:11 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/02 22:20:36 by nvan-der      ########   odam.nl         */
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

const Intern::FormInfo Intern::formInfos[] = {
	{"presidential pardon", &Intern::createPresidentialPardonForm},
	{"robotomy request", &Intern::createRobotomyRequestForm},
	{"shrubbery creation", &Intern::createShrubberyCreationForm},
};

const char *Intern::InvalidFormNameException::what() const throw() {
	return ("Invalid form type");
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const {
	for (size_t i = 0; i < sizeof(formInfos) / sizeof(formInfos[0]); i++) {
		if (name == formInfos[i].name) {
			return formInfos[i].creator(target);
		}
	}
	throw InvalidFormNameException();
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}