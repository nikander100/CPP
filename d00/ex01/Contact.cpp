#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::_setData(std::string asked, std::string *input)
{
	std::cout << asked;
	getline(std::cin, *input);
}

void	Contact::add()
{
	std::cout << "Adding new contact to the Phonebook....." << std::endl;
	_setData("Insert First Name: ", &(this->_first_name));
	_setData("Insert Last Name: ", &(this->_last_name));
	_setData("Insert Nickname: ", &(this->_nickname));
	_setData("Insert LogIn: ", &(this->_login));
	_setData("Insert Postal Address: ", &(this->_postal_address));
	_setData("Insert Email Address: ", &(this->_email_address));
	_setData("Insert Phone Number: ", &(this->_phone_number));
	_setData("Insert Birthday Date: ", &(this->_birthday_date));
	_setData("Insert Favorite Meal: ", &(this->_favorite_meal));
	_setData("Insert Underwear Color: ", &(this->_underwear_color));
	_setData("Insert Darkest Secret: ", &(this->_darkest_secret));
}

void	Contact::getShortInfo() const
{
	_formatIndex(this->_first_name);
	_formatIndex(this->_last_name);
	_formatIndex(this->_nickname);
	std::cout << std::endl;
}

void	Contact::getInfo() const
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

void	Contact::_formatIndex(std::string name) const
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
