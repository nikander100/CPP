#include "Array.hpp"
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
	Array<float> test;

	const unsigned int SIZE = 10;
	Array<int> intArray(SIZE);
	Array<int> intArray2(SIZE/2);

	std::cout << BLUE << "Int Array 1 intArray[i]=i*2: " << RESET << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i * 2;

	std::cout << GREEN << "Int Array 1: " << intArray << RESET << std::endl;

	toContinue();

	std::cout << BLUE << "Int Array 2 intArray2=intArray: " << RESET << std::endl;
	intArray2 = intArray;

	std::cout << "Int Array 2: " << intArray2 << std::endl;

	toContinue();

	try {
		std::cout << "Accessing a valid index: " << intArray[5] << std::endl;
		std::cout << "Accessing an invalid index: " << intArray[SIZE] << std::endl;
	} catch (...) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
