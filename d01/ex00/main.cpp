#include "Zombie.hpp"

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

// i use \n over endl as it doesn't flush the output buffer.
static void	toContinue(void) {
	std::cout <<  RED << "Press any key to continue...\n\n" << RESET;
	std::getchar();
}

int main(void) {
	Zombie *zombies[20];
	std::string names[20];
	set_names(names);

	std::cout << GREEN << "Allocating 20 zombies on heap\n" << RESET << "Allocating larger objects or arrays should be done on the heap due to the limited memory of the stack\n";
	for (int i = 0 ; i < 20; i++) {
		int random_variable = std::rand () % 20;
		zombies[i] = new Zombie(names[random_variable]);
	}

	toContinue();
	std::cout << GREEN << "Creating a \"Chumping zombie\" with the randomChump function\n" << RESET <<"randomChump creates on the stack since it's a single object and doesn't need to be accessed anymore after exiting the function\n\n";
	randomChump("Chumping zombie");

	toContinue();
	std::cout << std::endl <<  GREEN << "Announcing 5 zombies on the heap and destroying these 5 straight after announcing\n" << RESET;
	for(int i = 0; i < 5; i++) {
		zombies[i]->announce();
		delete(zombies[i]);
	}

	toContinue();
	std::cout << GREEN << "Creating 2 more zombies via randomChump\n" << RESET;
	randomChump("Another chumping zombie");
	randomChump("John");

	toContinue();
	// Using std::endl here because it flushes the buffer (it is not needed as the end of the fucntion also flushes the buffer but if you need to be sure the buffer is flushed use endl over \n)
	std::cout << GREEN << "Announcing and destroying the last 15 zombies on the heap" << RESET << std::endl;
	for (int i = 5; i < 20; i++) {
		zombies[i]->announce();
		delete(zombies[i]);
	}
}
