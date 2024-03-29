/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 19:32:30 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/04/19 16:28:19 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__
# include <iostream>

class Zombie {
	public:

	Zombie(std::string name);
	~Zombie();
	void	announce(void);

	private:
	std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
