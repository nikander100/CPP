/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 19:47:17 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/11/08 20:10:19 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();

	class InvalidFormNameException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	AForm *makeForm(const std::string &name, const std::string &target) const;
};