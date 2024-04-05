/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/05 22:18:35 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

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
	srand(time(NULL));
	
		Data originalData;
	originalData.str = "Test string";
	originalData.val = 123;

	std::cout << "Original data: " << originalData.str << ", " << originalData.val << std::endl;

	toContinue();

	// Serialize the Data object
	uintptr_t raw = Serializer::serialize(&originalData);

	// Print the serialized data
	std::cout << "Serialized data: " << std::hex << raw << std::dec << std::endl;

	toContinue();

	// Deserialize the raw data
	Data* deserializedData = Serializer::deserialize(raw);

	// Print the deserialized data
	std::cout << "Deserialized data: " << deserializedData->str << ", " << deserializedData->val << std::endl;
	
	toContinue();

	// Check that the deserialized Data object is the same as the original one
	if (deserializedData->str == originalData.str && deserializedData->val == originalData.val) {
		std::cout << "Test passed successfully!\n";
	} else {
		std::cout << "Test failed.\n";
	}

}

