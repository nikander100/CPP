/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 18:04:53 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/14 18:17:26 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain &copy);
	~Brain();
	// Assignment Operator
	Brain &operator = (const Brain &right);

	void getIdea() const;
	void getIdea(int index) const;
private:
	std::string ideas[100];
};

#endif
