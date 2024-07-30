#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::string const &database_filename) {
	loadDatabase(database_filename);
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::loadDatabase(std::string const &database_filename) {
	std::ifstream file(database_filename);
	if (!file.is_open()) {
		std::cerr << RED << "Error: could not open file " << database_filename << RESET << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == '#') {
			continue;
		}

		std::istringstream ss(line);
		std::string date;
		float price;

		if (std::getline(ss, date, ',') && ss >> price) {
			_priceDatabase[date] = price;
		}
	}

	file.close();
}

void BitcoinExchange::validateDate(std::string &date)
{
	if (date.size() != 10) {
		throw std::invalid_argument("Invalid date format: " + date);
	}

	std::string firstDate = _priceDatabase.begin()->first;
	std::string lastDate = _priceDatabase.rbegin()->first;
	if (date < firstDate || date > lastDate) {
		throw std::invalid_argument("Date is outside the range of available data: " + date);
	}

	std::regex dateRegex("(\\d{4})-(\\d{2})-(\\d{2})");
	std::smatch match;
	if (std::regex_match(date, match, dateRegex)) {
		if (match.size() == 4) { // match[0] is the entire match, [1], [2], [3] are the capture groups
			// int year = std::stoi(match[1]); // not using year for now
			int month = std::stoi(match[2]);
			int day = std::stoi(match[3]);
			if (month < 1 || month > 12 || day < 1 || day > 31) {
				throw std::invalid_argument("Invalid date: " + date);
			}
		} else {
			throw std::invalid_argument("Invalid date format: " + date);
		}
	} else {
		throw std::invalid_argument("Invalid date format: " + date);
	}
}

void BitcoinExchange::validateAmount(float amount)
{
	if (amount <= 0 || amount > 100000) {
			throw std::invalid_argument("Invalid Amount: " + std::to_string(amount));
	}
}


float BitcoinExchange::findPriceForDate(const std::string &date) {
		auto it = _priceDatabase.find(date);
		if (it == _priceDatabase.end()) {
			// Find the closest lower date
			it = _priceDatabase.lower_bound(date);
			if (it == _priceDatabase.begin() && it->first > date) {
				throw std::invalid_argument("No price data for date: " + date);
			}
			if (it == _priceDatabase.end() || it->first > date) {
				--it;
			}
		}
		return it->second;
	}

void BitcoinExchange::evaluatePrices(const std::string &filename) {
	std::ifstream file(filename);
	if (filename.rfind(".btc") != filename.length() - 4) {
		std::cerr << RED << "Error: File must be a .btc file: " << filename << RESET << std::endl;
		return;
	}
	if (!file.is_open()) {
		std::cerr << RED << "Error opening file: " << filename << RESET << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line.empty() || line.front() == '#') {
			continue;
		}
		try {
			std::istringstream ss(line);
			std::string date;
			float amount;

			if (!(std::getline(ss, date, '|') && ss >> amount)) {
				throw std::invalid_argument("Invalid input format: " + line);
			}

			// Trim trailing whitespace
			date.erase(date.find_last_not_of(" \n\r\t") + 1);

			validateDate(date);
			validateAmount(amount);
			float price = findPriceForDate(date);
			std::cout << date << " | " << amount << " BTC = " << amount * price << " USD" << std::endl;
		} catch (const std::invalid_argument& e) {
			// Handle parsing errors specifically
			std::cerr << RED << "Parsing error: " << e.what() << RESET << std::endl;
		} catch (const std::exception& e) {
			// Handle all other exceptions
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}

	file.close();
}