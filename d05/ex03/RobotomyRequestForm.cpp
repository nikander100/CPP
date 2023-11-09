/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 18:49:49 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/07 19:40:12 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", target, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &right) {
	if (this != &right) {
		AForm::operator=(right);
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "", 72, 45) {
}

void RobotomyRequestForm::action(const Bureaucrat &) const {
	std::cout << "Makes some drilling noises" << std::endl;
	if (rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << getTarget() << " has failed to be robotomized." << std::endl;
}