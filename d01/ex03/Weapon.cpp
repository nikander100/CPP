/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:31 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/11 17:17:16 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void): _type(std::string("default weapon")) {}

Weapon::Weapon(const char *type): _type(std::string(type)) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) const {
	return _type;
}

void Weapon::setType(const char *type) {
	_type = std::string(type);
}
