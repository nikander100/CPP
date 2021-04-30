#include <iostream>
#include "Sample.class.hpp"

int	main(void)
{
	Sample	instance1(42);
	Sample	instance2(42);

	if (&instance1 == &instance1)
		std::cout << "instance1 and insatnce1 are physically ==" << std::endl;
	else
		std::cout << "instance1 and insatnce1 are not physically ==" << std::endl;

	if (&instance1 == &instance2)
		std::cout << "instance1 and insatnce2 are physically ==" << std::endl;
	else
		std::cout << "instance1 and insatnce2 are not physically ==" << std::endl;

	if (instance1.compare(&instance1) == 0)
		std::cout << "instance1 and insatnce1 are structurally ==" << std::endl;
	else
		std::cout << "instance1 and insatnce1 are not structurally ==" << std::endl;

	if (instance1.compare(&instance2) == 0)
		std::cout << "instance1 and insatnce2 are structurally ==" << std::endl;
	else
		std::cout << "instance1 and insatnce2 are not structurally ==" << std::endl;

	return (0);
}