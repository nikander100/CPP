/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 18:17:35 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/10/18 18:31:43 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const &copy);
	~Bureaucrat();

	Bureaucrat&		operator=(Bureaucrat const &other);

	// Getters
	std::string		getName() const;
	unsigned int	getGrade() const;

	// Crementers
	void			incrementGrade();
	void			decrementGrade();

	class GradeTooHighException : public std::exception
	{};
	class GradeTooLowException : public std::exception
	{};

private:
	std::string		_name;
	unsigned int	_grade;
};

std::ostream&	operator<<(std::ostream &out, Bureaucrat const &bureaucrat);