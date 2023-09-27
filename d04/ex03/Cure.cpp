/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 18:58:44 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:25:28 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
}

Cure::Cure(const Cure& other) : AMateria(other){
}

Cure &Cure::operator=(const Cure &right){
	if (this != &right) {
		AMateria::operator=(right);
	}
	return (*this);
}

Cure::~Cure(){
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const {
	return (new Cure(*this));
}
