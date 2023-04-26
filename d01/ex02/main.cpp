#include <iostream>
#include <string>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define TEAL "\033[36m"

static void	toContinue(void) {
	std::cout <<  RED << "Press ENTER to continue...\n\n" << RESET;
	std::getchar();
}

int main(void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPTR = &brain;
	std::string &brainREF = brain;
	
	toContinue();
	std::cout << GREEN << "Printing out the memory adresses of brain, brainPTR and brainREF.\n\n" << RESET;
	std::cout << "[" << TEAL << "INFO" << RESET << "] Memory adress of brain:    " << "[" << TEAL << &brain << RESET << "].\n";
	std::cout << "[" << TEAL << "INFO" << RESET << "] Memory adress of brainPTR: " << "[" << TEAL << brainPTR << RESET << "].\n";
	std::cout << "[" << TEAL << "INFO" << RESET << "] Memory adress of brainREF: " << "[" << TEAL << &brainREF << RESET << "].\n";

	toContinue();
	std::cout << GREEN << "Printing out the values of brain, brainPTR and brainREF.\n\n" << RESET;
	std::cout << "[" << TEAL << "INFO" << RESET << "] Value of brain:    " << "[" << TEAL << brain << RESET << "].\n";
	std::cout << "[" << TEAL << "INFO" << RESET << "] Value of brainPTR: " << "[" << TEAL << *brainPTR << RESET << "].\n";
	std::cout << "[" << TEAL << "INFO" << RESET << "] Value of brainREF: " << "[" << TEAL << brainREF << RESET << "]." << std::endl;

	return (0);
}
