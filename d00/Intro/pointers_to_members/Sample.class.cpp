#include <iostream>
#include "Sample.class.hpp"

Sample::Sample() :
	foo(0)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample()
{
	std::cout << "Destructor Called" << std::endl;
	return;
}

void	Sample::bar() const
{
	std::cout << "Member function bar called" << std::endl;
	return;
}