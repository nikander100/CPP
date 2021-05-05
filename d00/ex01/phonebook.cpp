#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

void	get_contact_index(Contact contact[8], int contact_count)
{
	int		index = 0;

	std::cout << "\033[45;1m     Index|First Name| Last Name|  Nickname\033[0m" << std::endl;
	while (index < 8)
	{
		if (index < contact_count)
		{
			std::cout << "\033[44;1m";
			std::cout << std::right << std::setw(10) << index + 1;
			std::cout << "\033[0m";
			contact[index].get_short_info();
		}
		else
			std::cout << "\033[41;1m----------|----------|----------|----------\033[0m" << std::endl;
		index++;
	}
}

void	search(Contact contact[8], int contact_count)
{
	get_contact_index(contact, contact_count);
}

int		main()
{
	Contact		contact[8];
	std::string	arg;
	int			contact_count = 0;

	while (true)
	{
		std::cout << "Welcome to the Awesome phonebook! " <<
			"what would you like to do? you can use these commands(ADD,SEARCH,EXIT)." << std::endl;
		getline(std::cin, arg);
		if (arg == "ADD")
		{
			contact[contact_count++].add();
		}
		if (arg == "SEARCH")
		{
			search(contact, contact_count);
		}
		if (arg == "EXIT")
		{
			break ;
		}
	}
}