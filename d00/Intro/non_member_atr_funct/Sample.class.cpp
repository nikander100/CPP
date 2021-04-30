#include <iostream>
#include "Sample.class.hpp"

Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst += 1;

	return;
}

Sample::~Sample()
{
	std::cout << "Destructor Called" << std::endl;
	Sample::_nbInst -= 1;

	return;
}

int	Sample::getNbInst()
{
	return Sample::_nbInst;
}

int	Sample::_nbInst = 0;