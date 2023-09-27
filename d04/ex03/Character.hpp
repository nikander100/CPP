/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 18:58:59 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:52:50 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character(const std::string &name);
		Character(const Character &other);
		~Character();

		Character &operator=(const Character &right);

		std::string const &getName() const;
		void equip(AMateria *);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

	private:
		std::string _name;
		AMateria *_materia[4];
};
