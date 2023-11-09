/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 19:01:48 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/08 18:14:59 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", target, 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &right) {
	if (this != &right) {
		AForm::operator=(right);
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "", 145, 137) {
}

void ShrubberyCreationForm::action(const Bureaucrat &) const {
	std::ofstream file(getTarget() + "_shrubbery");
	if (!file.is_open()) {
		throw std::ofstream::failure("Error opening file");
	}
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << " \\//_/||__/ \\" << std::endl;
}