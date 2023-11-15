/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 19:14:13 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/16 00:03:30 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;
class AForm
{
public:
	AForm();
	AForm(const std::string &name);
	AForm(const std::string &name, const std::string &target);
	AForm(const std::string &name, unsigned int signGrade, unsigned int execGrade);
	AForm(const std::string &name, const std::string &target, unsigned int signGrade, unsigned int execGrade);
	AForm(const AForm &copy);
	~AForm();

	AForm &operator=(const AForm &right);

	// Getters
	std::string getName() const;
	std::string getTarget() const;
	bool getSigned() const;
	unsigned int getSignGrade() const;
	unsigned int getExecGrade() const;

	// Functions
	void beSigned(const Bureaucrat &candidate);
	void execute(const Bureaucrat &executor) const;
	virtual void action(const Bureaucrat &executer) const = 0;

	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	std::string const _name;
	std::string const _target;
	unsigned int const _signGrade;
	unsigned int const _execGrade;
	bool _signed;
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);