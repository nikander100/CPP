/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 18:17:35 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/02 21:20:36 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class AForm;
class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, unsigned int grade);
	Bureaucrat(const Bureaucrat &copy);
	virtual ~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat &right);

	// Getters
	const std::string getName() const;
	unsigned int getGrade() const;

	// Crementers
	void incrementGrade();
	void decrementGrade();

	// Functions
	void signForm(AForm &form) const;
	void executeForm(const AForm &form) const;

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

private:
	std::string		_name;
	unsigned int	_grade;
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &bureaucrat);