#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact
{
private:
	/* data */
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_login;
	std::string		_postal_address;
	std::string		_email_address;
	std::string		_phone_number;
	std::string		_birthday_date;
	std::string		_favorite_meal;
	std::string		_underwear_color;
	std::string		_darkest_secret;

	void			_set_data(std::string asked, std::string *input);
	void			_format_index(std::string name) const;

public:
	Contact();
	void			add();
	void			get_info() const;
	void			get_short_info() const;
};

#endif
