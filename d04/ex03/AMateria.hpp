/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 18:01:37 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:51:56 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp" 

class AMateria {
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		virtual ~AMateria();
		// Assignment Operator
		AMateria &operator=(const AMateria &right);

		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);

	protected:
		std::string _type;
};
