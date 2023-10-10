/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/21 19:02:50 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
	// const AAnimal* meta = new AAnimal();
	const AAnimal* i = new Cat();
	const AAnimal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();

	toContinue();
	const WrongAnimal* x = new WrongCat();
	x->makeSound(); //will output the WrongAnimal sound!

	delete i;
	delete j;
	delete x;
	// delete meta;
	
	return (0);
}
