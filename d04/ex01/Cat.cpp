/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:31:12 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/03/28 19:16:41 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

extern bool debug;

Cat::Cat() : _brain(new Brain()){
	if (debug)
		std::cout << "[DEBUG] Cat constructor called." << std::endl;
	type = "Cat";
}

Cat::~Cat() {
	if (_brain)
		delete _brain;
	if (debug)
		std::cout << "[DEBUG] Cat destructor called MEOW." << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy), _brain(new Brain(*copy._brain)){}

Cat &Cat::operator=(const Cat &right) {
	if (this != &right) {
		// Call the base class assignment operator to handle the 'type' member variable
		Animal::operator=(right);
		if (_brain)
			delete _brain;
		_brain = new Brain(*right._brain);
	} 
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "The " << type << " goes MEOWWWWWWWWWW." << std::endl;
}

const Brain *Cat::getBrain() const {
	return (_brain);
}