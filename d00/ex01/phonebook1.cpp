#include "Contact.hpp"

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
	std::string arg;
	int			index;

	get_contact_index(contact, contact_count);
	std::cout << "From which contact would you like too see more info: ";
	std::getline(std::cin, arg);
	std::cout << std::endl;
	if (std::cin.eof())
		return ;
	if (arg.length() != 1 || arg[0] == '0' || !std::isdigit(arg[0]) || (arg[0] - '0') > contact_count)
		std::cout << "please give a valid input: (1-" << contact_count << ")." << std::endl << std::endl;
	else
	{
		index = arg[0] - '0';
		contact[index - 1].get_info();
	}
}

int		main()
{
	Contact		contact[8];
	std::string	arg;
	int			contact_count = 0;
	int			contact_loop_count = 0;

	while (true)
	{
		std::cout << "Welcome to the Awesome phonebook! " <<
			"what would you like to do? you can use these commands(ADD,SEARCH,EXIT)." << std::endl;
		getline(std::cin, arg);
		if (arg == "ADD")
		{
			if (contact_count == 8)
			{
				if (contact_loop_count == 8)
					contact_loop_count = 0;
				contact[contact_loop_count++].add();
			}
			else
				contact[contact_count++].add();
		}
		if (arg == "SEARCH") 
		{
			if (contact_count == 0)
				std::cout << "There are no contacts in the phonebook." << std::endl << std::endl;
			else
				search(contact, contact_count);
		}
		if (arg == "EXIT" || std::cin.eof())
			break ;
	}
}