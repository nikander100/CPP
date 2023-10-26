/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 18:17:35 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/10/26 20:48:53 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Form;
class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, unsigned int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat &right);

	// Getters
	std::string getName() const;
	unsigned int getGrade() const;

	// Crementers
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form) const;

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