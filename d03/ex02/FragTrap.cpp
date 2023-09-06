/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 19:01:14 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/06 19:36:34 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	if (debug)
		std::cout << "[DEBUG] FragTrap is being constructed." << std::endl;
	setHealth(100);
	setStamina(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	if (debug)
		std::cout << "[DEBUG] A named FragTrap is being constructed." << std::endl;
	setHealth(100);
	setStamina(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &fix) : ClapTrap(fix) {
	if (debug)
		std::cout << "[DEBUG] FragTrap copying constructor called." << std::endl;
}

FragTrap::~FragTrap() {
	if (debug)
		std::cout << "[DEBUG] FragTrap deconstructinator is being called." << std::endl;
}

void FragTrap::highFivesGuy() {
	std::cout << std::endl << "FragTrap " << getName() << ": give me a high five, lets goooooooooooooooooooooooooooooooooo." << std::endl;
}
