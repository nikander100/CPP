/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:31:12 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/12 16:49:20 by nvan-der      ########   odam.nl         */
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

Cat::Cat(const Cat& copy) {
	type = copy.type;
}

Cat &Cat::operator=(const Cat &right) {
	if (this != &right) {
		type = right.type;
	} 
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "The " << type << " goes MEOWWWWWWWWWW." << std::endl;
}
