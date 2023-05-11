/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:34 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/11 17:15:47 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void) {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
