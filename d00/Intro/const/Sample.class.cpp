#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(float const f ) :
	pi(f), qd(42)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor Called" << std::endl;
	return;
}

void	Sample::bar(void) const
{
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->pi = " << this->qd << std::endl;

	// this->qd = 0; const member function can't assign thins:  (cannot assign to non-static data member within const member function 'bar')

	return;
}