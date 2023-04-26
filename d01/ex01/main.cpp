/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 18:18:01 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/04/26 18:18:02 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <ctime>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

static void set_names(std::string *names) {
	names[0] = "Axenth";
	names[1] = "Syndicate";
	names[2] = "GoonSwarmFederation";
	names[3] = "CircleOfTwo";
	names[4] = "Test";
	names[5] = "PandamicHorde";
	names[6] = "Mia";
	names[7] = "Neverdie";
	names[8] = "Codam";
	names[9] = "42";
	names[10] = "DFA";
	names[11] = "Hussk";
	names[12] = "Nifflheim";
	names[13] = "Yggdrasil";
	names[14] = "CDF";
	names[15] = "K-max";
	names[16] = "Nanashana";
	names[17] = "Eve";
	names[18] = "PlanetCalypso";
	names[19] = "Thule";
}

bool isNumeric(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

void deleteZombieHorde(Zombie *horde) {
	delete[] horde;
}

void announceHorde(Zombie *horde, int N) {
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
}

size_t getHordeSize() {
	std::string input;
	size_t size = 20;
	std::getline(std::cin, input);
	while (!isNumeric(input)) {
		std::cout << "Invalid input, please enter a numeric value: ";
		std::getline(std::cin, input);
	}
	std::stringstream ss(input);
	ss >> size;
	if (size == 0 || size > 50)
		size = 20;
	return (size);
}

// i use \n over endl as it doesn't flush the output buffer.
static void	toContinue(void) {
	std::cout <<  RED << "Press ENTER to continue...\n\n" << RESET;
	std::getchar();
}

int main(void) {
	std::string names[20];
	std::string input;
	size_t hordeSize = 20;
	set_names(names);

	toContinue();
	std::cout << GREEN << "Allocating a horde of 20 zombies with the name: " << names[15] << RESET << "\n\nAllocating larger objects or arrays should be done on the heap due to the limited memory of the stack\n";
	Zombie *horde = zombieHorde(hordeSize, names[15]);
	announceHorde(horde, hordeSize);
	deleteZombieHorde(horde);

	toContinue();
	std::cout << GREEN << "Allocating a horde of zombies with the name: " << names[15] << RESET << "\n\n";
	std::cout << "Enter the size of the zombie horde: ";
	hordeSize = getHordeSize();
	horde = zombieHorde(hordeSize, names[15]);
	announceHorde(horde, hordeSize);
	deleteZombieHorde(horde);

	toContinue();
	std::cout << GREEN << "Allocating 5 hordes of 5 zombies, where every horde has a random name: " << names[15] << RESET << "\n\n";
	hordeSize = 5;
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		Zombie* horde = zombieHorde(hordeSize, names[rand() % 20]);
		announceHorde(horde, hordeSize);
		deleteZombieHorde(horde);
		toContinue();
	}
}
