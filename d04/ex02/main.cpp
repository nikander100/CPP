/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/02 17:09:24 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iomanip>

bool debug = false;

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

/**
 * @brief The main entry point of the program.
 *
 * This function is responsible for initializing the program, checking the command line arguments,
 * creating an array of Animal objects, and performing some operations on them.
 * If the command line argument is "DEBUG=true", it enables debug mode and prints debug messages.
 * Otherwise, it prints a message indicating that debug mode is disabled.
 * After that, it creates an array of 10 Animal pointers, where the first 5 pointers point to Cat objects
 * and the remaining 5 pointers point to Dog objects.
 * It then creates a copy of the first Cat object in the array and prints the ideas stored in its brain
 * as well as the ideas stored in the brain of the first Cat object in the array.
 * Finally, it deletes the dynamically allocated objects and returns 0.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of strings containing the command line arguments.
 * @return The exit status of the program.
 */
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
	
	// toContinue();
	// AAnimal Test; //This should throw Abstract Class error during compilation.
	toContinue();
	AAnimal* animals[10];
	
	for (int i = 0; i < 10; i++)
	{
		if (i >= 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		animals[i]->makeSound();
	}
	Cat copy(*(Cat *)animals[0]);
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << std::setw(50) << std::left << copy.getBrain()->getIdea(i); // get idea from the newly copied cat
		std::cout << std::setw(50) << std::left << ((Cat *)animals[0])->getBrain()->getIdea(i) << std::endl; // get idea from the original cat.
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	
	return (0);
}
