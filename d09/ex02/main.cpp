#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << RED << "Error: " << RESET << "No input provided" << std::endl;
		return EXIT_FAILURE;
	}
	PmergeMe pmm(ac, av);
	pmm.sortAndPrint();
	return EXIT_SUCCESS;
}
