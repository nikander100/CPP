#include "whatever.hpp"

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
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	toContinue();

	std::cout << "swap(a, b)" << std::endl;
	whatever::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	toContinue();

	std::cout << "min(a, b) = " << whatever::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << whatever::max(a, b) << std::endl;

	toContinue();

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;

	toContinue();

	std::cout << "swap(c, d)" << std::endl;
	whatever::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << "min(c, d) = " << whatever::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << whatever::max(c, d) << std::endl;

	return 0;
}