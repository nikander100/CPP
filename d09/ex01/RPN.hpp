#pragma once

#include <algorithm>
#include <iostream>
#include <stack>
#include <sstream>


#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"
#define BLUE "\033[1;34m"


class RPN {
	public:
		static double calculate(const std::string &expression);
	
	private:
		static bool isOperator(const std::string &token);
		static double performOperation(const std::string &op, double operand1, double operand2);
};