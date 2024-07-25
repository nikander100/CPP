#include "Span.hpp"
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

static void test1() {
	std::cout << BLUE << "=== Test 1 ===" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

static void test2() {
	std::cout << BLUE << "=== Test 2 ===" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try {
		sp.addNumber(42);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

static void test3() {
	std::cout << BLUE << "=== Test 3 ===" << RESET << std::endl;
	Span sp = Span(10727);
	std::vector<int> v;
	for (int i = 0; i < 10727; i++) {
		v.push_back(i);
	}
	sp.addNumber(v.begin(), v.end());
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

int main() {
	std::cout << YELLOW << "=== Subject tests ===" << RESET << std::endl;
	test1();
	toContinue();
	test2();
	toContinue();
	test3();
	return EXIT_SUCCESS;
}