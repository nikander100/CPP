#include "Zombie.hpp"
#include <stdlib.h>

#define RESET "\033[0m"
#define GREEN "\033[32m"

static std::string *set_names(std::string *names)
{
	names[0] = "Axenth";
	names[1] = "Syndicate";
	names[2] = "GoonSwarmFederation";
	names[3] = "CircleOfTwo";
	names[4] = "Test";
	names[5] = "PandamicHorde";
	names[6] = "Mia";
	names[7] = "Torreto";
	names[8] = "Codam";
	names[9] = "42";
	names[10] = "Asgard";
	names[11] = "Fae";
	names[12] = "Nifflheim";
	names[13] = "Yggdrasil";
	names[14] = "Hellheim";
	names[15] = "Hades";
	names[16] = "Elysium";
	names[17] = "Alfheim";
	names[18] = "AlfheimOnline";
	names[19] = "Thule";

	return (names);
}

int main(void)
{
	Zombie *zombies[20];
	std::string names[20];
	set_names(names);

	std::cout << GREEN << "Allocating 20 zombies on heap" << RESET << std::endl << "Allocating larger objects or arrays should be done on the heap due to the limited memory of the stack" << std::endl << std::endl;
	for (int i = 0 ; i < 20; i++)
	{
		int random_variable = std::rand () % 20;
		zombies[i] = new Zombie(names[random_variable]);
	}

	std::cout << GREEN << "Creating a \"Chumping zombie\" with the randomChump function" << RESET << std::endl << "randomChump creates on the stack since it's a single object and doesn't need to be accessed anymore after exiting the function" << std::endl << std::endl;
	randomChump("Chumping zombie");

	std::cout << std::endl <<  GREEN << "Announcing 5 zombies on the heap and destroying these 5 straight after announcing" << RESET << std::endl << std::endl;
	for(int i = 0; i < 5; i++)
	{
		zombies[i]->announce();
		delete(zombies[i]);
	}


	std::cout << std::endl << GREEN << "Creating 2 more zombies via randomChump" << RESET << std::endl << std::endl;
	randomChump("Another chumping zombie");
	randomChump("John");


	std::cout << std::endl << GREEN << "Announcing and destroying the last 15 zombies on the heap" << RESET << std::endl << std::endl;
	for (int i = 5; i < 20; i++)
	{
		zombies[i]->announce();
		delete(zombies[i]);
	}
}
