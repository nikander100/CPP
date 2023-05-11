/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 19:55:16 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/11 20:03:11 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

	#include <string>

class Harl {
public:

	Harl();
	Harl(const std::string name);
	~Harl();
	void complain(std::string level);

private:

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	std::string _name;
};

#endif
