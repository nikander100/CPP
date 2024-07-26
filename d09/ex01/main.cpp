#include "RPN.hpp"

int main() {
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
	std::cout << "Result: " << RPN::calculate("5 0 /") << std::endl;
	// Expected output: Error: Division by zero

	// Test case 6: Evaluate an expression with insufficient operands
	std::cout << "Result: " << RPN::calculate("5 +") << std::endl;
	// Expected output: Error: Insufficient operands

	// Test case 7: Evaluate an expression with invalid operator
	std::cout << "Result: " << RPN::calculate("5 2 ^") << std::endl;
	// Expected output: Error: Invalid operator

	// Test case 8: Evaluate an invalid expression
	std::cout << "Result: " << RPN::calculate("5 2 + +") << std::endl;
	// Expected output: Error: Invalid expression

	// Test case 9: Evaluate an empty expression
	std::cout << "Result: " << RPN::calculate("") << std::endl;
	// Expected output: Error: Invalid expression

    return 0;
}

