/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 18:59:05 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:28:23 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type) {
}

AMateria::AMateria(const AMateria &other) : _type(other._type){
}

AMateria &AMateria::operator=(const AMateria &right) {
	if (this != &right) {
		_type = right._type;
	} 
	return (*this);
}

AMateria::~AMateria(){
}

std::string const &AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter &target) {
	(void)target;
}