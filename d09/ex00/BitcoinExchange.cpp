#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::string const &database_filename) {
    loadDatabase(database_filename);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    (void)src;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
    (void)rhs;
    return *this;
}

void BitcoinExchange::loadDatabase(std::string const &database_filename) {
    std::ifstream file(database_filename);
    if (!file.is_open()) {
        std::cerr << RED << "Error: could not open file " << database_filename << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
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

    std::regex dateRegex("\\d{2}/\\d{2}/\\d{4}");
    if (!std::regex_match(date, dateRegex)) {
        throw std::invalid_argument("Invalid date format: " + date);
    }

    std::string monthStr = date.substr(0, 2);
    std::string dayStr = date.substr(3, 2);

    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        throw std::invalid_argument("Invalid date: " + date);
    }
}

void BitcoinExchange::validateAmount(float price)
{
    if (price <= 0 || price > 100000) {
            throw std::invalid_argument("Invalid price: " + std::to_string(price));
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
    if (!file.is_open()) {
        std::cerr << RED << "Error opening file: " << filename << RESET << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float amount;

        if (std::getline(ss, date, '|') && ss >> amount) {
            // Trim trailing whitespace
            date.erase(date.find_last_not_of(" \n\r\t") + 1);
            
            try {
                validateDate(date);
                validateAmount(amount);
                float price = findPriceForDate(date);
                std::cout << date << " | " << amount << " BTC = " << amount * price << " USD" << std::endl;
            } catch (const std::exception& e) {
                std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
                continue;
            }
        }
    }

    file.close();
}