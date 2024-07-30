#include "MutantStack.hpp"
#include <iostream>

bool debug = false;

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"
#define BLUE "\033[1;34m"
#define WYSI 727

int main() {
	MutantStack<int> stack;
	
	// Push elements into the stack
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(WYSI);
	stack.push(40);
	stack.push(50);

	// Print the elements in the stack
	std::cout << "Stack elements: ";
	for (const auto& element : stack) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	// Pop an element from the stack
	stack.pop();

	// Print the top element in the stack
	std::cout << "Top element: " << stack.top() << std::endl;

	// Check if the stack is empty
	std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << std::endl;

	// Get the size of the stack
	std::cout << "Stack size: " << stack.size() << std::endl;

	// Clear the stack
	stack.clear();

	// Check if the stack is empty after clearing
	std::cout << "Is stack empty after clearing? " << (stack.empty() ? "Yes" : "No") << std::endl;

	return EXIT_SUCCESS;
}