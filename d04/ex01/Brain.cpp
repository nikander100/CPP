/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 18:04:50 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/03/28 19:30:37 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

extern bool debug;

Brain::Brain() {
	if (debug) 
		std::cout << "Brain default constructor called" << std::endl;
	const std::string defaults [] = {
		"i want to play lootius.io",
		"i want to play entropia universe",
		"I want a global in entropia universe",
		"I want a hall of fame in entropia universe",
		"i want a global on lootius.io",
		"i want to make money on lootius.io",
		"i want to make money on entropia universe",
	};
	for (int i = 0; i < 100; i++) {
		ideas[i] = defaults[rand() % (sizeof(defaults) / sizeof(std::string))];
	}
}

Brain::~Brain() {
	if (debug)
		std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
	if (debug)
		std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = copy.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &right) {
	if (this != &right) {
		if (debug)
			std::cout << "Brain assignment operator called" << std::endl;
		for (int i = 0; i < 100; i++) {
			ideas[i] = right.ideas[i];
		}
	}
	return (*this);
}

const std::string& Brain::getIdea() const {
	return ideas[rand() % 100];
}

const std::string& Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		static const std::string invalidIndex = "Invalid index";
		return invalidIndex;
	}
	return ideas[index];
}

const std::string* Brain::getIdeas() const {
	return (ideas);
}
