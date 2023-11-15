/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 20:05:25 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/16 00:06:09 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("defaultForm"), _signGrade(1), _execGrade(1), _signed(false) {
}

AForm::AForm(const std::string &name) : _name(name), _signGrade(1), _execGrade(1), _signed(false) {
}

AForm::AForm(const std::string& name, const std::string& target)
	: _name(name), _target(target), _signGrade(1), _execGrade(1), _signed(false) {
}

AForm::AForm(const std::string &name, const unsigned int signGrade, const unsigned int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const std::string &name, const std::string &target, const unsigned int signGrade, const unsigned int execGrade)
	: _name(name), _target(target), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &copy)
	: _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade), _signed(copy._signed) {
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &right) {
	if (this != &right) {
		_signed = right._signed;
	}
	return (*this);
}

unsigned int AForm::getSignGrade() const {
	return (_signGrade);
}

unsigned int AForm::getExecGrade() const {
	return (_execGrade);
}

std::string AForm::getName() const {
	return (_name);
}

std::string AForm::getTarget() const {
	return (_target);
}

bool AForm::getSigned() const {
	return (_signed);
}

void AForm::beSigned(const Bureaucrat &candidate) {
	if (!_signed)
	{
		if (candidate.getGrade() <= _signGrade)
			_signed = true;
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::AlreadySignedException();
}

void AForm::execute(const Bureaucrat &executor) const {
	if (_signed) {
		if (executor.getGrade() <= _execGrade)
			action(executor);
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::NotSignedException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low.");
}

const char *AForm::AlreadySignedException::what() const throw() {
	return ("Form is already signed.");
}

const char *AForm::NotSignedException::what() const throw() {
	return ("Form is not signed.");
}

std::ostream	&operator<<(std::ostream &out, const AForm &form) {
	out << "Form " << form.getName() << " is ";
	if (!form.getSigned())
		out << "not ";
	out << "signed. It requires a grade " << form.getSignGrade() << " to sign and a grade " << form.getExecGrade() << " to execute.";
	return (out);
}