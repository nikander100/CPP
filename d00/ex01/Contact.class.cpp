#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

Contact::Contact()
{
	return;
}

void	Contact::_set_data(std::string asked, std::string *input)
{
	std::cout << asked;
	getline(std::cin, *input);
}

void	Contact::add()
{
	std::cout << "Adding new contact to the Phonebook....." << std::endl;
	_set_data("insert First Name: ", &(this->_first_name));
	_set_data("insert Last Name: ", &(this->_last_name));
	_set_data("insert Nickname: ", &(this->_nickname));
	_set_data("insert Login: ", &(this->_login));
	_set_data("insert Postal Address: ", &(this->_postal_address));
	_set_data("insert Email Address: ", &(this->_email_address));
	_set_data("insert Phone Number: ", &(this->_phone_number));
	_set_data("insert Birthday Date: ", &(this->_birthday_date));
	_set_data("insert Favorite Meal: ", &(this->_favorite_meal));
	_set_data("insert Underwear Color: ", &(this->_underwear_color));
	_set_data("insert Darkest Secret: ", &(this->_darkest_secret));
}

void	Contact::_format_index(std::string name) const
{
	std::cout << "\033[44;1m|\033[0m";
	if (name.length() > 10)
	{
		name.resize(9);
		name+= ".";
	}
	std::cout << "\033[44;1m" << std::right << std::setw(10) << (name) << "\033[0m";
}

void	Contact::get_short_info() const
{
	_format_index(this->_first_name);
	_format_index(this->_last_name);
	_format_index(this->_nickname);
}