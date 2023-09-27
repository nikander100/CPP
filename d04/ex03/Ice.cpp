/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 18:59:14 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:25:42 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
}

Ice::Ice(const Ice& other) : AMateria(other){
}

Ice &Ice::operator=(const Ice &right){
	if (this != &right) {
		AMateria::operator=(right);
	}
	return (*this);
}

Ice::~Ice(){
}

void Ice::use(ICharacter &target) {
	std::cout << " shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const {
	return (new Ice(*this));
}
