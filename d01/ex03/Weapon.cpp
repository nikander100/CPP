/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:31 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/11 17:27:34 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void): _type("default weapon") {}

Weapon::Weapon(const std::string &type): _type(type) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) const {
	return _type;
}

void Weapon::setType(const std::string &type) {
	_type = type;
}
