#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	getContact();
	void	run();

private:
	static const int _maxContacts = 8;
	Contact	_contact[_maxContacts];
	int		_numOfContacts;
	int		_contactLoopCount;

	void	_getContactIndex();

};

#endif

