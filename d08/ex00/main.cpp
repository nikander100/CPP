#include "easyfind.hpp"
#include <iostream>

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

int main() {
	std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int searchValue;
	std::cout << "Enter a value to search: ";
	std::cin >> searchValue;

	try {
		std::vector<int>::iterator vecResult = easyfind(vec, searchValue);
		std::cout << GREEN << "Value found in vector at index: " << std::distance(vec.begin(), vecResult) << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Value not found in vector" << RESET << std::endl;
	}

	try {
		std::list<int>::iterator lstResult = easyfind(lst, searchValue);
		std::cout << GREEN << "Value found in list at index: " << std::distance(lst.begin(), lstResult) << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Value not found in list" << RESET << std::endl;
	}

	toContinue();
	return EXIT_SUCCESS;
}