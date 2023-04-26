/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Humanb.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:45 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/04/26 19:38:58 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
public:

	HumanB(std::string name);
	~HumanB(void);
	void attack(void);
	void setWeapon(Weapon& weapon);

private:

	std::string _name;
	Weapon  *_weapon{NULL};
};
