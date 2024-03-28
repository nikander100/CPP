/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 18:04:53 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/03/28 19:19:57 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>
# include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain &copy);
	~Brain();
	// Assignment Operator
	Brain &operator = (const Brain &right);

	// Getters
	const std::string& getIdea() const;
	const std::string& getIdea(int index) const;
	const std::string* getIdeas() const;
private:
	std::string ideas[100];
};

#endif