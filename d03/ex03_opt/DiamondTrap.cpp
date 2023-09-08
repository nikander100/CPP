/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/08 16:40:29 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/08 17:18:03 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	if (debug)
		std::cout << "[DEBUG] DiamondTrap is being constructed." << std::endl;
	
	setHealth(FragTrap::getHealth());
	setStamina(ScavTrap::getStamina());
	setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
	if (debug)
		std::cout << "[DEBUG] A named DiamondTrap is being constructed." << std::endl;
	_name = name;
	setHealth(FragTrap::getHealth());
	setStamina(ScavTrap::getStamina());
	setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &fix) : ClapTrap(fix), ScavTrap(fix), FragTrap(fix) {
	if (debug)
		std::cout << "[DEBUG] DiamondTrap copying constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	if (debug)
		std::cout << "[DEBUG] DiamondTrap deconstructinator is being called." << std::endl;
}

void DiamondTrap::WhoAmI() {
	std::cout << "<< I Am " << _name << " and My Granfather was " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
s