/*
 * C++ implementation of random number generation based on the C# version
 * of the Rand function from StrategyNerd LLC.
 *
 * This code is adapted from a similar function used in a C# project developed
 * by StrategyNerd LLC. The C++ implementation is provided for use within the
 * context of this project only and should not be copied or used in other
 * projects without appropriate authorization.
 *
 * (C) 2023 StrategyNerd LLC - All rights reserved.
 * Adapted by Nikander van der Schee (nvan-der) for project [C++ - Module 06]
 */
 
#ifndef __RAND_HPP__
	#define __RAND_HPP__

#include <random>
#include <stdexcept>
#include <cmath>

namespace StrategyNerd {
	class Rand {
	public:
		static int64_t RandomNumber(int64_t min, int64_t max) {
		// Validate input range
		if (min >= max) {
			max = min;
		}

		// Increment max to make the range inclusive
		++max;
	
		// Generate a random 64-bit integer
		std::uniform_int_distribution<int64_t> dist(min, max);
		int64_t randomNum = dist(mt);
	
		// Check for division by zero
		if ((max - min) + min <= 0) {
			throw std::runtime_error("Divided By Zero Caught");
		}
	
		// Calculate the final random number within the specified range
		return (std::abs(randomNum % (max - min)) + min);
	};

	private:
		inline static std::mt19937_64 mt{std::random_device{}()};
	};
}

#endif // __STRATEGYNERDRAND_H__