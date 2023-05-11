/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:36 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/11 17:20:48 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::attack(void) {
	std::cout << _name << " attacks with ";
	if (_weapon != NULL)
		std::cout << "their " << _weapon->getType() << std::endl; 
	else
		std::cout << "their fists!!" << std::endl; 
}
void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}
