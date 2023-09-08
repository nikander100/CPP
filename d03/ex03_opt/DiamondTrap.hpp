/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   diamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/08 16:40:40 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/08 17:16:09 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

extern bool debug;

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &copy);
	~DiamondTrap();

	void WhoAmI();
	void attack(const std::string& target);

private:
	std::string _name;
};

#endif
