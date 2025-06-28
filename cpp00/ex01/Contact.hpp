#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();

		// Getters
		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nickname() const;
		std::string	get_secret() const;
		std::string	get_phone_number() const;

		// Setters
		void		set_first_name(std::string arg);
		void		set_last_name(std::string arg);
		void		set_nickname(std::string arg);
		void		set_secret(std::string arg);
		void		set_phone_number(std::string arg);

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_secret;
		std::string	_phone_number;
};



#endif
