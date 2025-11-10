/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:58:14 by dioferre          #+#    #+#             */
/*   Updated: 2025/11/10 11:56:07 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->_index = -1;
}

Phonebook::~Phonebook()
{
}


int	Phonebook::Add()
{

	if (_index >= MAX_CONTACTS || _index == -1)
		_index = 0;

	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;

	firstName = readInput("First Name: ");
	lastName = readInput("Last Name: ");
	nickname = readInput("Nickame: ");
	phoneNumber = readInput("Phone number: ");
	secret = readInput("Darkest secret: ");

	contacts[_index].set_first_name(firstName);
	contacts[_index].set_last_name(lastName);
	contacts[_index].set_nickname(nickname);
	contacts[_index].set_phone_number(phoneNumber);
	contacts[_index].set_secret(secret);

	_index++;
	return (0);
}

int	Phonebook::Search()
{
	std::string	input;
	int			i;

	printContacts();
	input = readInput("Select a contact index: ");

	if (input.empty())
		return (1);

	i = atoi(input.c_str());

	if (_index - 1 < i)
	{
		std::cout << RED << "[ERROR]: " << RESET << "No entry for index " << i << std::endl;
	}
	else
	{
		std::cout << "Displaying contact information for index: " << i << std::endl;
		displayContactInfo(contacts[i]);
	}
	return (0);
}

void	Phonebook::printContacts()
{
	printHeader();
	for (short i = 0; i < MAX_CONTACTS; i++)
	{
		printIndividualContact(contacts[i], i);
	}
	std::cout << std::setfill('-') << std::setw(46) << "\n";
}

void	displayContactInfo(Contact& contact)
{
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}
