/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 18:59:16 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:53:01 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		~Ice();
		// Assignment Operator
		Ice &operator=(const Ice &right);

		AMateria *clone() const;
		void use(ICharacter &target);
};