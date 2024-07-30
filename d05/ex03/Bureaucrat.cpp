/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 17:04:30 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/05/02 16:41:30 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("BureauKraat"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
}

Bureaucrat::~Bureaucrat() {
}

const std::string Bureaucrat::getName() const {
	return (_name);
}

unsigned int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << _name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low.");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (out);
}