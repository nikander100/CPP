#include "easyfind.hpp"
#include <iostream>
#include <numeric>
#include <random>


bool debug = false;

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"
#define BLUE "\033[1;34m"


int main() {
	std::vector<int> vec(20);
	std::list<int> lst(20);
	
	// Fill vec with random numbers from 0 to 19
	std::iota(vec.begin(), vec.end(), 0);
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(vec.begin(), vec.end(), g);
	
	// Fill lst with vector values
	lst.assign(vec.begin(), vec.end());

	// Print vec
	std::cout << BLUE << "Vector (I == Index): ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << RESET << "I" << (it - vec.begin()) << ": " << BLUE << *it << " ";
	}
	std::cout << RESET << std::endl;

	int searchValue;
	std::cout << "Enter a value to search: ";
	while (!(std::cin >> searchValue)) {
		std::cout << "Invalid input. Please enter a numeric value: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	


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

	return EXIT_SUCCESS;
}