/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 19:55:28 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/17 16:07:05 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"

Harl::Harl(): _name("Harl") {}
Harl::~Harl(void) {}

Harl::Harl(const std::string name): _name(name) {}

void Harl::complain(std::string level) {
	typedef void (Harl::*ComplainFunction)(void);
	const std::string levels[4] = {"debug", "info", "warning", "error"};
	const ComplainFunction functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << BRIGHTRED << "[" << TEAL << _name << BRIGHTRED << "] "
		<< "Invalid complaint level: " << level << RESET << std::endl;
}

void Harl::debug() {
	std::cout << GREEN << "[" << TEAL << _name << GREEN << "] "
		<< "Debug complaint." << RESET << std::endl;
}

void Harl::info() {
	std::cout << GREEN << "[" << TEAL << _name << GREEN << "] "
		<< "Info complaint." << RESET << std::endl;
}

void Harl::warning() {
	std::cout << YELLOW << "[" << TEAL << _name << YELLOW << "] "
		<< "Warning complaint." << RESET << std::endl;
}

void Harl::error() {
	std::cout << RED << "[" << TEAL << _name << RED << "] "
		<< "Error complaint." << RESET << std::endl;
}

