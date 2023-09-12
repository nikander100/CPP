/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 18:20:14 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/12 18:25:23 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

extern bool debug;

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	if (debug)
		std::cout << "[DEBUG] WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.type) {}

WrongAnimal::~WrongAnimal() {
	if (debug)
		std::cout << "[DEBUG] WrongAnimal destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &right) {
	if (this != &right) {
		type = right.type;
	} 
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "The " << type << " Makes " << type << " Noises." << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}
