/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 18:58:53 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:33:42 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string &name) : _name(name) {
	for (int i=0; i<4; i++) {
		_materia[i] = nullptr;
	}
}

Character::Character(const Character &other) : _name(other._name) {
	for (int i=0; i<4; i++) {
		_materia[i] = (other._materia[i]) ? other._materia[i]->clone() : nullptr;
	}
}

Character &Character::operator=(const Character &right) {
	if (this != &right) {
		_name = right._name;
		for (int i=0; i<4; i++) {
			_materia[i] = (right._materia[i]) ? right._materia[i]->clone() : nullptr;
		}
	}
	return (*this);
}

Character::~Character() {
	for (int i=0; i<4; i++) {
		if (_materia[i]){
			delete _materia[i];
		}
	}
}

std::string const &Character::getName() const {
	return (_name);
}

void Character::equip(AMateria *materia) {
	if (materia) {
		for (int i=0; i<4; i++) {
			if (!_materia[i]) {
				_materia[i] = materia;
				break ;
			}
		}
	}
}
void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3) {
		_materia[idx] = nullptr;
	}
}
void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx <= 3 && _materia[idx]) {
		_materia[idx]->use(target);
	}
}