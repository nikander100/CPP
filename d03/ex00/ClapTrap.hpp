/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 13:41:05 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/08 15:57:17 by nvan-der      ########   odam.nl         */
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


	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	unsigned int getStamina() const;
	unsigned int getHealth() const;
	unsigned int getAttackDamage() const;
	std::string getName() const;

	void setStamina(unsigned int StaminaVal);
	void setHealth(unsigned int healthVal);
	void setAttackDamage(unsigned int damageVal);

private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

};

#endif
