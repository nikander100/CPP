/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 19:01:09 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/06 19:15:42 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

extern bool debug;

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &copy);
	~FragTrap();

	void highFivesGuy();

private:
	// I have no private data

};

#endif
