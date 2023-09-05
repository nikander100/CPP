/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 17:38:50 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/05 18:07:49 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
bool debug = false;

ScavTrap::ScavTrap() : ClapTrap(), _hitPoints(100), _staminaPoints(50), _attackDamage(20), gatekeeper(false) {
	if (debug)
		std::cout << "[DEBUG] ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name), _hitPoints(100), _staminaPoints(50), _attackDamage(20), gatekeeper(false) {
	if (debug)
		std::cout << "[DEBUG] ScavTrap default constructor called." << std::endl;
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
	std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}