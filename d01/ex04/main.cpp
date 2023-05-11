/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 18:12:31 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/05/11 19:22:18 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceStringInFile(const std::string &filename, const std::string &s1, const std::string &s2) {
	// Open input file.
	std::ifstream inputFile(filename);
	if (!inputFile.good()) {
		std::cerr << "Error: File '" << filename << "' does not exist." << std::endl;
		return ;
	}

	// Create the output file.
	std::string outputFilename = filename + ".repalce";
	std::ofstream outputFile(outputFilename, std::ofstream::app);
	if (!outputFile.good()) {
		std::cerr << "Error: File '" << outputFilename << "' does not exist." << std::endl;
		return ;
	}

	// Read inputfile line for line and replace occurrences of s1 with s2.
	std::string line;
	while (std::getline(inputFile, line)) {
		std::string replacedLine;
		size_t pos = 0;
		while (pos < line.length()) {
			size_t foundPos = line.find(s1, pos);
			if (foundPos == std::string::npos) {
				replacedLine += line.substr(pos);
				break;
			}
			replacedLine += line.substr(pos, foundPos - pos);
			replacedLine += s2;
			pos = foundPos + s1.length();
		}
		outputFile << replacedLine << std::endl;
	}
	inputFile.close();
	outputFile.close();
	std::cout << "Replacement complete. Output written to " << outputFilename << std::endl;
}

bool isValidString(const std::string& str) {
	return !str.empty();
}

int main(int ac, char **av) {
	if (ac < 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (!isValidString(s1) || !isValidString(s2)) {
		std::cerr << "Error: Invalid strings. Both s1 and s2 must be non-empty." << std::endl;
		return 1;
	}

	replaceStringInFile(filename, s1, s2);

	return (0);
}
