/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Humanb.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:45 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/11 17:20:06 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
public:

	HumanB(std::string name);
	~HumanB(void);
	void attack(void);
	void setWeapon(Weapon& weapon);

private:

	std::string _name;
	Weapon *_weapon;
};

#endif
