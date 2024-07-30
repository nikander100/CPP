#include "RPN.hpp"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		// No additional arguments were provided; run default tests
		std::cout << "Running default tests...\n";

		// Test case 1: Evaluate a simple expression
		std::cout << "Result: " << RPN::calculate("5 2 +") << std::endl;
		// Expected output: 7

		// Test case 2: Evaluate an expression with multiple operations
		std::cout << "Result: " << RPN::calculate("3 4 + 2 *") << std::endl;
		// Expected output: 14

		// Test case 3: Evaluate an expression with subtraction and division
		std::cout << "Result: " << RPN::calculate("10 5 - 2 /") << std::endl;
		// Expected output: 2.5

		// Test case 4: Evaluate an expression with multiple operations and operands
		std::cout << "Result: " << RPN::calculate("3 4 + 2 * 5 -") << std::endl;
		// Expected output: 9
		
		// Test case 5: Evaluate an expression with division by zero
		try {
			std::cout << "Result: " << RPN::calculate("5 0 /") << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		// Test case 6: Evaluate an expression with insufficient operands
		try {
			std::cout << "Result: " << RPN::calculate("5 +") << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		// Test case 7: Evaluate an expression with invalid operator
		try {
			std::cout << "Result: " << RPN::calculate("5 2 ^") << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		// Test case 8: Evaluate an invalid expression
		try {
			std::cout << "Result: " << RPN::calculate("5 2 + +") << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		// Test case 9: Evaluate an empty expression
		try {
			std::cout << "Result: " << RPN::calculate("") << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	} else {
		try {
			std::string expression;
			for (int i = 1; i < argc; ++i) {
				if (i > 1) expression += " ";
				expression += argv[i];
			}
			std::cout << "Result: " << RPN::calculate(expression) << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	return EXIT_SUCCESS;
}