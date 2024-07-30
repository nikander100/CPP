#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <stdexcept>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"
#define BLUE "\033[1;34m"

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const &database_filename);
		BitcoinExchange(BitcoinExchange const &src) = delete;
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &rhs) = delete;

		void loadDatabase(std::string const &database_filename);
		void evaluatePrices(const std::string &filename);


	private:
		std::map<std::string, float> _priceDatabase;

		void validateDate(std::string &date);
		void validateAmount(float amount);
		float findPriceForDate(const std::string &date);
};