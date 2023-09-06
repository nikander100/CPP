/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 17:38:50 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/06 18:08:54 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), gatekeeper(false) {
	if (debug)
		std::cout << "[DEBUG] ScavTrap default constructor called." << std::endl;
	setHealth(100);
	setStamina(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name), gatekeeper(false) {
	if (debug)
		std::cout << "[DEBUG] ScavTrap with name constructor called." << std::endl;
	setHealth(100);
	setStamina(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& fix) : ClapTrap(fix), gatekeeper(fix.gatekeeper) {
	if (debug)
		std::cout << "[DEBUG] ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap() {
	if (debug)
		std::cout << "[DEBUG] ScavTrap deconstructor called." << std::endl;
}

void ScavTrap::guardGate() {
	gatekeeper = true;
	std::cout << "ScavTrap " << getName() << " has entered Gate Keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << getName() << " attacks " << target;
	std::cout << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}
