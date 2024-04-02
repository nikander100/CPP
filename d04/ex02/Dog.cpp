/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 16:48:44 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/02 16:59:12 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

extern bool debug;

Dog::Dog() : _brain(new Brain()) {
	if (debug)
		std::cout << "[DEBUG] Dog constructor called." << std::endl;
	type = "Dog";
}

Dog::~Dog() {
	if (_brain)
		delete _brain;
	if (debug)
		std::cout << "[DEBUG] Dog destructor called WOOF." << std::endl;
}

Dog::Dog(const Dog& copy) : AAnimal(copy), _brain(new Brain(*copy._brain)){}

Dog &Dog::operator=(const Dog &right) {
	if (this != &right) {
		// Call the base class assignment operator to handle the 'type' member variable
		AAnimal::operator=(right);
		if (_brain)
			delete _brain;
		_brain = new Brain(*right._brain);
	} 
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "The " << type << " goes WOOF WOOF WOOF." << std::endl;
}

const Brain *Dog::getBrain() const {
	return (_brain);
}