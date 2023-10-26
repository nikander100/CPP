/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 20:05:25 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/10/26 20:52:28 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("defaultForm"), _signed(false), _signGrade(1), _execGrade(1) {
}

Form::Form(const std::string &name) : _name(name), _signed(false), _signGrade(1), _execGrade(1) {
}

Form::Form(const std::string &name, const unsigned int signGrade, const unsigned int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &copy)
	: _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &right) {
	if (this != &right) {
		_signed = right._signed;
	}
	return (*this);
}

unsigned int Form::getSignGrade() const {
	return (_signGrade);
}

unsigned int Form::getExecGrade() const {
	return (_execGrade);
}

std::string Form::getName() const {
	return (_name);
}

bool Form::getSigned() const {
	return (_signed);
}

void Form::beSigned(const Bureaucrat &candidate) {
	if (!_signed)
	{
		if (candidate.getGrade() <= _signGrade)
			_signed = true;
		else
			throw Form::GradeTooLowException();
	}
	else
		throw Form::AlreadySignedException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low.");
}

const char *Form::AlreadySignedException::what() const throw() {
	return ("Form is already signed.");
}

std::ostream	&operator<<(std::ostream &out, const Form &form) {
	out << "Form " << form.getName() << " is ";
	if (!form.getSigned())
		out << "not ";
	out << "signed. It requires a grade " << form.getSignGrade() << " to sign and a grade " << form.getExecGrade() << " to execute.";
	return (out);
}