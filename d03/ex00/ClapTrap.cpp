/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 13:45:05 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/06 17:37:24 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
bool debug = false;

ClapTrap::ClapTrap() : _name("HolyMoly"), _hitPoints(10), _staminaPoints(10), _attackDamage(0) {
	if (debug)
		std::cout << "[DEBUG] Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _staminaPoints(10), _attackDamage(0) {
	if (debug)
		std::cout << "[DEBUG] ClapTrap with Name constructor called." << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap& fix) : _name(fix._name), _hitPoints(fix._hitPoints),
					_staminaPoints(fix._staminaPoints), _attackDamage(fix._attackDamage) {
	if (debug)
		std::cout << "[DEBUG] Copy Constructor called." << std::endl;
}

ClapTrap::~ClapTrap() {
	if (debug)
		std::cout << "[DEBUG] Deconstructor called." << std::endl;
}

// Assignment Operator
ClapTrap &ClapTrap::operator=(const ClapTrap &right) {
	if (debug)
		std::cout << "[DEBUG] Copy assignment operator called: ";
	if (this != &right) {
		if (debug)
			std::cout << "Pass." << std::endl;
		_name = right._name;
		_hitPoints = right._hitPoints;
		_staminaPoints = right._staminaPoints;
		_attackDamage = right._attackDamage;
	} else
		if (debug)
			std::cout << "Fail." << std::endl;
	return (*this);
}
// =======
// Getters
// =======

std::string ClapTrap::getName() const {
	return(_name);
}

unsigned int ClapTrap::getAttackDamage() const {
	return(_attackDamage);
}

unsigned int ClapTrap::getHealth() const {
	return(_hitPoints);
}

unsigned int ClapTrap::getStamina() const {
	return(_staminaPoints);
}

// =======
// Setters
// =======

void ClapTrap::setAttackDamage(unsigned int damageVal) {
	_attackDamage = damageVal;
}

void ClapTrap::setHealth(unsigned int healthVal) {
	_hitPoints = healthVal;
}

void ClapTrap::setStamina(unsigned int staminaVal) {
	_staminaPoints = staminaVal;
}

// Attack function
void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _staminaPoints <= 0) {
		std::cout << "ClapTrap " << _name << " cannot attack. It has no hit points or stamina left." << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	_staminaPoints -= 1;
}

// Be repaired function
void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _staminaPoints <= 0) {
		std::cout << "ClapTrap " << _name << " cannot be repaired. It has no hit points or stamina left." << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
	_hitPoints += amount;
	_staminaPoints -= 1;
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " cannot take damage. It has no hit points left." << std::endl;
		return;
	}

	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and has no hit points left!" << std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. It has " << _hitPoints << " hit points remaining." << std::endl;
	}
}
