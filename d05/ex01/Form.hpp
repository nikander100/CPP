/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 19:14:13 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/02 20:49:59 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Bureaucrat;
class Form
{
public:
	Form();
	Form(const std::string &name);
	Form(const std::string &name, unsigned int signGrade, unsigned int execGrade);
	Form(const Form &copy);
	virtual ~Form();

	Form &operator=(const Form &right);

	const std::string getName() const;
	bool getSigned() const;
	unsigned int getSignGrade() const;
	unsigned int getExecGrade() const;

	void beSigned(const Bureaucrat &candidate);

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

private:
	std::string const _name;
	bool _signed;
	unsigned int const _signGrade;
	unsigned int const _execGrade;
};

std::ostream	&operator<<(std::ostream &out, const Form &form);