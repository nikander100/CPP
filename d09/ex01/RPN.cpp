#include "RPN.hpp"

double RPN::calculate(const std::string &expression) {

	const std::string validChars = "0123456789+-*/ ";

	// Check if the expression contains only numbers and operators
	if (expression.find_first_not_of(validChars) != std::string::npos) {
		throw std::runtime_error("Error: Expression contains invalid characters");
	}

	std::stack<double> stack;
	std::istringstream iss(expression);
	std::string token;

	// Check if the expression is just a single number
	double number;
	if (iss >> number) {
		char remaining;
		if (!(iss >> remaining)) { // Check if there's anything left in the stream
			return number; // Return the number if it's the only thing in the expression
		}
	}

	// Reset stream
	iss.clear();
	iss.seekg(0, std::ios::beg);


	while (iss >> token) {
		if (isOperator(token)) {
			if (stack.size() < 2) {
				throw std::runtime_error("Error: Insufficient operands");
			}
			double operand2 = stack.top();
			stack.pop();
			double operand1 = stack.top();
			stack.pop();
			double result = performOperation(token, operand1, operand2);
			stack.push(result);
		} else {
			double operand;
			std::istringstream(token) >> operand;
			stack.push(operand);
		}
	}
	if (stack.size() != 1) {
		throw std::runtime_error("Error: Invalid expression");
	}
	return stack.top();
}

bool RPN::isOperator(const std::string &token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

double RPN::performOperation(const std::string &op, double operand1, double operand2) {
	if (op == "+") {
		return operand1 + operand2;
	} else if (op == "-") {
		return operand1 - operand2;
	} else if (op == "*") {
		return operand1 * operand2;
	} else if (op == "/") {
		if (operand2 == 0) {
			throw std::runtime_error("Error: Division by zero");
		}
		return operand1 / operand2;
	}
	throw std::runtime_error("wtf happened here, what did you do to make this happen this sohuldnt happen..");
}
