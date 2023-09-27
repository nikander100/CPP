/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:47:12 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

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

	IMateriaSource* grimoire = new MateriaSource();
	grimoire->learnMateria(new Ice());
	grimoire->learnMateria(new Cure());
	grimoire->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = grimoire->createMateria("ice");
	me->equip(tmp);
	tmp = grimoire->createMateria("cure");
	me->equip(tmp);

	ICharacter* asta = new Character("asta");
	tmp = grimoire->createMateria("ice");
	asta->equip(tmp);

	me->use(0, *asta);
	me->use(1, *asta);
	asta->use(0, *me);

	me->unequip(1);
	me->equip(NULL);
	me->equip(grimoire->createMateria("cure"));
	me->use(1, *asta);

	ICharacter* yami = new Character("yami");
	me->use(0, *yami);
	yami->use(0, *me);

	delete asta;
	delete me;
	delete yami;
	delete grimoire;

	return (0);
}
