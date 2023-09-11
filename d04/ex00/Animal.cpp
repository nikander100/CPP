/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:31:05 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/11 18:52:48 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
bool debug = false;

Animal::Animal() : type("Animal") {
	if (debug)
		std::cout << "[DEBUG] Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type) {}

Animal::~Animal() {
	if (debug)
		std::cout << "[DEBUG] Animal destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &right) {
	if (this != &right) {
		type = right.type;
	} 
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "The " << type << " Makes " << type << " Noises." << std::endl;
}

std::string Animal::getType() const {
	return (type);
}
