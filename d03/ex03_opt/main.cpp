/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/08 16:24:03 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"
#define BLUE "\033[1;34m"


static void toContinue(void) {
	std::cout << TEAL << "\nPress ENTER to continue...\n" << RESET;
	std::getchar();
}

int main(int argc, char **argv) {
	if (argc > 1) {
		std::string arg = argv[1];
		if (arg == "DEBUG=true") {
			std::cout << BRIGHTRED <<"[INFO] " << RESET << "DEBUG == true";
			debug = true;
		}
	}
	else {
		std::cout << BRIGHTRED <<"[INFO] " << RESET << "DEBUG == False" << std::endl;
		std::cout << BRIGHTRED <<"[INFO] " << RESET << "Run using `" << TEAL 
			<<"./runme DEBUG=true" << RESET <<"` to enable constructor/destructor messages.";
	}
	
	toContinue();
	ClapTrap mandrake("Mandrake");

	// Create a ScavTrap named "nika"
	ScavTrap nika("Nika");

	// Mandrake attacks Nika
	mandrake.attack(nika.getName());
	nika.takeDamage(mandrake.getAttackDamage());
	toContinue();

	// Nika repairs itself
	nika.beRepaired(10);
	std::cout << "Nika now has [" << nika.getHealth() << "] hit points." << std::endl;
	toContinue();

	// Nika attacks Mandrake
	nika.attack(mandrake.getName());
	mandrake.takeDamage(nika.getAttackDamage());
	toContinue();

	// Mandrake attacks Nika again
	mandrake.attack(nika.getName());
	toContinue();

	// Create a ScavTrap object
	ScavTrap scav("Scav");

	// ScavTrap enters gatekeeper mode
	scav.guardGate();

	// Create a FragTrap object
	FragTrap frag("Fraggy");
	toContinue();

	// FragTrap gives a high five
	frag.highFivesGuy();
	toContinue();
	
	return (0);
}
