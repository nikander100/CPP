/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:31:12 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/02/21 19:13:26 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

extern bool debug;

Cat::Cat() {
	if (debug)
		std::cout << "[DEBUG] Cat constructor called." << std::endl;
	type = "Cat";
}

Cat::~Cat() {
	if (debug)
		std::cout << "[DEBUG] Cat destructor called MEOW." << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {}

Cat &Cat::operator=(const Cat &right) {
	if (this != &right) {
		// Call the base class assignment operator to handle the 'type' member variable
		Animal::operator=(right);
	} 
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "The " << type << " goes MEOWWWWWWWWWW." << std::endl;
}
