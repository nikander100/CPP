/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 13:41:05 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/06/20 15:13:33 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

extern bool debug;

# include <iostream>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap();

	// Assignment Operator
	ClapTrap &operator = (const ClapTrap &right);

	std::string getName() const;
	unsigned int getAttackDamage() const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _staminaPoints;
	unsigned int _attackDamage;

};

#endif
