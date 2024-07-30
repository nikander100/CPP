#include "BitcoinExchange.hpp"

int main(int ac, char* av[]) {
	if (ac != 2) {
		std::cerr << TEAL << "Usage: " << av[0] << " <input_file>" << RESET << std::endl;
		return EXIT_FAILURE;
	}

	BitcoinExchange btcExchange("data.csv");
	// btcExchange.loadDatabase("data.csv");
	btcExchange.evaluatePrices(av[1]);

	return EXIT_SUCCESS;
}


