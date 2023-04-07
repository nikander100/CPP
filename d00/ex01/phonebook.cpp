#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _numOfContacts(0), _contactLoopCount(0) {}

void PhoneBook::addContact() {
	if (this->_numOfContacts == this->_maxContacts) {
		if (this->_contactLoopCount == this->_maxContacts)
			this->_contactLoopCount = 0;
		this->_contact[this->_contactLoopCount++].add();
	}
	else
		this->_contact[this->_numOfContacts++].add();
}

void PhoneBook::getContact() {
	this->_getContactIndex();
	std::cout << "From which contact would you like to see more info: ";
	std::string arg;
	std::getline(std::cin, arg);
	std::cout << std::endl;
	if (std::cin.eof())
		return ;
	if (arg.length() != 1 || arg[0] == '0' || !std::isdigit(arg[0]) || (arg[0] - '0') > this->_numOfContacts)
		std::cout << "Please give a valid input: (1-" << this->_numOfContacts << ")." << std::endl << std::endl;
	else {
		int index = arg[0] - '0';
		_contact[index - 1].get_info();
	}
}

void PhoneBook::run() {
	std::string arg;
	while (true) {
		std::cout << "Welcome to the Awesome phonebook! " <<
			"what would you like to do? you can use these commands(ADD, SEARCH, EXIT)." << std::endl;
		std::getline(std::cin, arg);
		if (arg == "ADD") {
			this->addContact();
		} 
		else if (arg == "SEARCH") {
			if (this->_numOfContacts == 0)
				std::cout << "There are no contacts in the phonebook." << std::endl << std::endl;
			else
				this->getContact();
		} 
		else if (arg == "EXIT" || std::cin.eof())
			break;
		else 
			continue;
	}
}


void PhoneBook::_getContactIndex() {
	std::cout << "\033[45;1m     Index|First Name| Last Name|  Nickname\033[0m" << std::endl;
	for (int index; index < this->_maxContacts; index++) {
		if (index < this->_numOfContacts) {
			std::cout << "\033[44;1m";
			std::cout << std::right << std::setw(10) << index + 1;
			std::cout << "\033[0m";
			_contact[index].get_short_info();
		} else
			std::cout << "\033[41;1m----------|----------|----------|----------\033[0m" << std::endl;
	}
}
