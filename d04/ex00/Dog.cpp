/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 16:48:44 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/02/21 19:13:36 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

extern bool debug;

Dog::Dog() {
	if (debug)
		std::cout << "[DEBUG] Dog constructor called." << std::endl;
	type = "Dog";
}

Dog::~Dog() {
	if (debug)
		std::cout << "[DEBUG] Dog destructor called WOOF." << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy){}

Dog &Dog::operator=(const Dog &right) {
	if (this != &right) {
		// Call the base class assignment operator to handle the 'type' member variable
		Animal::operator=(right);
	} 
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "The " << type << " goes WOOF WOOF WOOF." << std::endl;
}
