/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:41 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/04/26 19:35:25 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEPAON_HPP__
# include <string>

class Weapon {
	public:

	Weapon(void);
	Weapon(std::string &type);
	~Weapon(void);

	const	std::string &getType(void) const;
	void	setType(const std::string &type);

	
	private:
	
	std::string _type;
};

#endif

