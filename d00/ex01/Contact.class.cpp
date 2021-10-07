#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

Contact::Contact()
{}

void	Contact::_set_data(std::string asked, std::string *input)
{
	std::cout << asked;
	getline(std::cin, *input);
}

void	Contact::add()
{
	std::cout << "Adding new contact to the Phonebook....." << std::endl;
	_set_data("Insert First Name: ", &(this->_first_name));
	_set_data("Insert Last Name: ", &(this->_last_name));
	_set_data("Insert Nickname: ", &(this->_nickname));
	_set_data("Insert LogIn: ", &(this->_login));
	_set_data("Insert Postal Address: ", &(this->_postal_address));
	_set_data("Insert Email Address: ", &(this->_email_address));
	_set_data("Insert Phone Number: ", &(this->_phone_number));
	_set_data("Insert Birthday Date: ", &(this->_birthday_date));
	_set_data("Insert Favorite Meal: ", &(this->_favorite_meal));
	_set_data("Insert Underwear Color: ", &(this->_underwear_color));
	_set_data("Insert Darkest Secret: ", &(this->_darkest_secret));
}

void	Contact::_format_index(std::string name) const
{
	std::cout << "\033[44;1m|\033[0m";
	if (name.length() > 10)
	{
		name.resize(9);
		name+= ".";
	}
	std::cout << "\033[44;1m";
	std::cout << std::right << std::setw(10) << name;
	std::cout << "\033[0m";
}

void	Contact::get_short_info() const
{
	_format_index(this->_first_name);
	_format_index(this->_last_name);
	_format_index(this->_nickname);
	std::cout << std::endl;
}

void	Contact::get_info() const
{
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Login: " << this->_login << std::endl;
	std::cout << "Postal address: " << this->_postal_address << std::endl;
	std::cout << "Email address: " << this->_email_address << std::endl;
	std::cout << "Phone number: " << this->_phone_number << std::endl;
	std::cout << "Birthday date: " << this->_birthday_date << std::endl;
	std::cout << "Favorite meal: " << this->_favorite_meal << std::endl;
	std::cout << "Underwear color: " << this->_underwear_color << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret<< std::endl;
	std::cout << std::endl << std::endl;
}