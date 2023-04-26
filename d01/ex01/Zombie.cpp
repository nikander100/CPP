/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 19:32:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/04/26 18:44:37 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define TEAL "\033[36m"
#define RESET "\033[0m"

Zombie::Zombie(): _name("default") {}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie() {
	std::cout << "[" << TEAL << "DEBUG" << RESET << "] Calling destructor of Zombie[" << TEAL << _name << RESET << "] at adress ["<< TEAL << this << RESET << "]." << std::endl;
}

void Zombie::announce() {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}
