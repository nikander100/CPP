/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 18:26:41 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/12 18:27:05 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

extern bool debug;

WrongCat::WrongCat() {
	if (debug)
		std::cout << "[DEBUG] WrongCat constructor called." << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat() {
	if (debug)
		std::cout << "[DEBUG] WrongCat destructor called MEOW." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) {
	type = copy.type;
}

WrongCat &WrongCat::operator=(const WrongCat &right) {
	if (this != &right) {
		type = right.type;
	} 
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "The " << type << " goes MEOWWWWWWWWWW." << std::endl;
}
