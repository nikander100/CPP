/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:41 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/11 17:16:17 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__
# include <string>

class Weapon {
	public:

	Weapon(void);
	Weapon(const char *type);
	~Weapon(void);

	const	std::string &getType(void) const;
	void	setType(const char *type);

	
	private:
	
	std::string _type;
};

#endif

