/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 18:28:57 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/02 21:01:18 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", target, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &right) {
	if (this != &right) {
		AForm::operator=(right);
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "", 25, 5) {
}

void PresidentialPardonForm::action(const Bureaucrat &) const {
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}