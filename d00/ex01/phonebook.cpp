#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

void	get_contac_index(Contact Contact[8], int contact_count)
{
	int		index = 0;
}

void	search(Contact contacts[8], int contact_count)
{

}

int		main()
{
	Contact		contact[8];
	std::string	arg;
	int			contact_count = 0;

	while (true)
	{
		std::cout << "Welcome to the Awesome phonebook! what would you like to do? you can use these commands(ADD,SEARCH,EXIT)." << std::endl;
		getline(std::cin, arg);
		if (arg == "ADD")
		{
			contact[contact_count++].add();
		}
		if (arg == "SEARCH")
		{
			search(contact, contact_count);
		}
		// if (arg == "EXIT")
		// {
		// 	break ;
		// }
	}
}