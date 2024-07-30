#include "Span.hpp"
#include <iostream>
#include <iomanip>
#include <numeric>

bool debug = false;

#define WIDTH 30
#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"
#define BLUE "\033[1;34m"
#define FUCHSIA "\033[35m"
#define BOLD "\033[1m"
#define FORMAT std::left << std::setw(WIDTH)
#define WYSI "727"

// TODO : implement this in other files as well.

std::string center(const std::string& text, int width) {
	int totalPadding = width - text.length();
	int paddingSide = totalPadding / 2;
	int paddingExtra = totalPadding % 2;
	return std::string(paddingSide, ' ') + text + std::string(paddingSide + paddingExtra, ' ');
}

static void toContinue(void) {
	std::cout << TEAL << "\n" << center("Press ENTER to continue...", WIDTH) << "\n" << RESET;
	std::getchar();
}

static void test1() {
	std::cout << std::endl << FUCHSIA << BOLD << center("=== Test 1 ===", WIDTH) << RESET << std::endl;
	std::cout << BLUE << FORMAT << "Shortest span should be:" << "2" << std::endl;
	std::cout << FORMAT << "Longest span should be:" << "14" << RESET << std::endl << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << GREEN << FORMAT<< "Shortest span:" << sp.shortestSpan() << std::endl;
	std::cout << FORMAT<< "Longest span:" << sp.longestSpan() << RESET << std::endl;
}

static void test2() {
	std::cout << std::endl << FUCHSIA << BOLD << center("=== Test 2 ===", WIDTH) << RESET << std::endl;
	std::cout << BLUE << FORMAT << "Shortest span should be:" << "2" << std::endl;
	std::cout << FORMAT << "Longest span should be:" << "14" << std::endl;
	std::cout << FORMAT << "Should throw an exception:" << "Span is full" << RESET << std::endl << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << GREEN << FORMAT << "Shortest span:" << sp.shortestSpan() << std::endl;
	std::cout << FORMAT << "Longest span:" << sp.longestSpan() << std::endl;
	try {
		sp.addNumber(42);
	} catch (std::exception &e) {
		std::cout << RED << FORMAT << "Error" << e.what() << RESET << std::endl;
	}
}

static void test3() {
	std::cout << std::endl << FUCHSIA << BOLD << center("=== Test 3 ===", WIDTH) << RESET << std::endl;
	std::cout << BLUE << FORMAT << "Shortest span should be:" << "1" << std::endl;
	std::cout << FORMAT << "Longest span should be:" << "10" << WYSI << RESET << std::endl << std::endl;
	Span sp = Span(10728);
	std::vector<int> v(10728);
	std::iota(v.begin(), v.end(), 0);
	sp.addNumber(v.begin(), v.end());
	std::cout << GREEN << FORMAT << "Shortest span:" << sp.shortestSpan() << std::endl;
	std::cout << FORMAT << "Longest span:" << sp.longestSpan() << RESET << std::endl;
	std::cout << FUCHSIA << BOLD << center("=== WHEN YOU SEE IT ===", WIDTH) << RESET << std::endl;
}

int main() {
	std::cout << YELLOW << center("=== Subject tests ===", WIDTH) << RESET << std::endl;
	try {
		test1();
		toContinue();
		test2();
		toContinue();
		test3();
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}