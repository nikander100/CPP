/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:43 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/04/26 19:31:09 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);
	void attack(void);

private:

	std::string _name;
	Weapon &_weapon;
};
