/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 15:53:39 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/17 16:43:55 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"

static void	toContinue(void) {
	std::cout <<  TEAL << "\nPress ENTER to continue...\n" << RESET;
	std::getchar();
}

int main() {
	Harl harl, karen("Karen"), kevin("Kevin");
	harl.complain("debug");
	toContinue();
	harl.complain("info");
	toContinue();
	harl.complain("warning");
	toContinue();
	harl.complain("error");
	toContinue();
	harl.complain("invalid");

	toContinue();

	karen.complain("debug");
	toContinue();
	karen.complain("info");
	toContinue();
	karen.complain("warning");
	toContinue();
	karen.complain("error");
	toContinue();
	karen.complain("invalid");

	toContinue();

	kevin.complain("debug");
	toContinue();
	kevin.complain("info");
	toContinue();
	kevin.complain("warning");
	toContinue();
	kevin.complain("error");
	toContinue();
	kevin.complain("invalid");

	return (0);
}
