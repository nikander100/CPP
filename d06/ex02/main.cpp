/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/04/09 22:18:45 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Rand.hpp"

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

using StrategyNerd::Rand;

// Generates instance of A, B or C based on randomgen.
Base *generate(void) {
	u_int64_t randomNumber = Rand::RandomNumber(1, 3);
	if (randomNumber == 1) {
		return new A();
	} else if (randomNumber == 2) {
		return new B();
	} else if (randomNumber == 3) {
		return new C();
	}
	return nullptr;
}

template <typename T>
bool PrintType(Base* p, const char* typeName) {
	if (auto casted = dynamic_cast<T*>(p)) {
		std::cout << typeName;
		return true;
	}
	return false;
}

// Prints actual type pointed out by p pointer.
void identify(Base *p)
{
	if (PrintType<A>(p, "A")) return;
	if (PrintType<B>(p, "B")) return;
	if (PrintType<C>(p, "C")) return;
}

void identify1(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr) {
		std::cout << "A";
	} else if (dynamic_cast<B*>(p) != nullptr) {
		std::cout << "B";
	} else if (dynamic_cast<C*>(p) != nullptr) {
		std::cout << "C";
	}
}

template <typename T>
bool PrintType(Base& p, const char* typeName) {
	try {
		(void)dynamic_cast<T&>(p);
		std::cout << typeName;
		return true;
	} catch (const std::bad_cast&) {
		return false;
	}
}

// Prints actual type pointed out by p refference.
void identify(Base &p)
{
	if (PrintType<A>(p, "A")) return;
	if (PrintType<B>(p, "B")) return;
	if (PrintType<C>(p, "C")) return;
}
void identify1(Base &p)
{
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
		return;
	}
	catch (const std::bad_cast &e) { /* Not A */ }
	
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
		return;
	}
	catch (const std::bad_cast &e) { /* Not B */ }
	
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
		return;
	}
	catch (const std::bad_cast &e) { /* Not C */ }
}

int main() {
	const int amt = 50;
	std::cout << typeid(amt).name();
	Base* instances[amt];
	
	for (int i = 0; i < amt; i++)
		instances[i] = generate();

	// Identifies the type of each instance using a pointer.
	std::cout << "Identify pointer:" << std::endl;
	for (int i = 0; i < amt; i++)
		identify(instances[i]);
	std::cout << std::endl;
	
	toContinue();

	// Identifies the type of each instance using a reference.
	std::cout << "Identifiy reference:" << std::endl;
	for (int i = 0; i < amt; i++) {
		identify(*instances[i]);
	}
	std::cout << std::endl;

	toContinue();

	// Identifies the type of each instance using a pointer.
	std::cout << "Identify pointer:" << std::endl;
	for (int i = 0; i < amt; i++)
		identify1(instances[i]);
	std::cout << std::endl;
	
	toContinue();

	// Identifies the type of each instance using a reference.
	std::cout << "Identifiy reference:" << std::endl;
	for (int i = 0; i < amt; i++) {
		identify1(*instances[i]);
	}
	std::cout << std::endl;

	for (int i = 0; i < amt; i++)
		delete instances[i];

	return 0;
}