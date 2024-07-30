#include "iter.hpp"

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
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char charArray[] = "hello world";

	std::cout << BLUE << "Original int array: " << RESET << std::endl;
	iter(intArray, 5, print<int>);
	std::cout << std::endl << GREEN << "Incremented int array: " << RESET << std::endl;
	iter(intArray, 5, increment<int>);
	iter(intArray, 5, print<int>);

	toContinue();

	std::cout << std::endl << BLUE << "Original double array: " << RESET << std::endl;
	iter(doubleArray, 5, print<double>);
	std::cout << std::endl << GREEN << "Doubled double array: " << RESET << std::endl;
	iter(doubleArray, 5, doubleValue<double>);
	iter(doubleArray, 5, print<double>);

	toContinue();

	std::cout << std::endl << BLUE << "Original char array: " << RESET << std::endl;
	iter(charArray, 5, print<char>);
	std::cout << std::endl << GREEN << "Capitalized char array: " << RESET << std::endl;
	iter(charArray, 5, capitalize<char>);
	iter(charArray, 5, print<char>);

	return 0;
}