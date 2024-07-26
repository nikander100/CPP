#include "RPN.hpp"

double RPN::calculate(const std::string &expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    try {
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
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return -1;
    }
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
    throw std::runtime_error("Error: Invalid operator");
}
