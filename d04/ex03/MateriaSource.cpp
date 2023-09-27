/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 18:59:23 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:16:18 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i=0; i<4; i++) {
		_materia[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i=0; i<4; i++) {
		_materia[i] = (other._materia[i]) ? other._materia[i]->clone() : nullptr;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &right) {
	if (this != &right) {
		for (int i=0; i<4; i++) {
			_materia[i] = (right._materia[i]) ? right._materia[i]->clone() : nullptr;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i=0; i<4; i++) {
		if (_materia[i]){
			delete _materia[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (materia) {
		for (int i=0; i<4; i++) {
			if (!_materia[i]) {
				_materia[i] = materia;
				break ;
			}
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i=0; i<4; i++) {
		if (_materia[i] && _materia[i]->getType() == type) {
			return (_materia[i]->clone());
		}
	}
	return (nullptr);
}