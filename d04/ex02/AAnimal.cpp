/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:31:05 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/02 16:52:41 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

extern bool debug;

AAnimal::AAnimal() : type("Animal") {
	if (debug)
		std::cout << "[DEBUG] Animal constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : type(copy.type) {}

AAnimal::~AAnimal() {
	if (debug)
		std::cout << "[DEBUG] Animal destructor called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &right) {
	if (this != &right) {
		type = right.type;
	} 
	return (*this);
}

std::string AAnimal::getType() const {
	return (type);
}
