/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prints.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:57:58 by dioferre          #+#    #+#             */
/*   Updated: 2025/05/09 17:45:05 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <stdlib.h>



void	printHeader(void)
{
	std::cout << std::setw(16) <<  std::setfill(' ') << GREEN << "[ Welcome to Phonebook ]" << RESET << "\n";
	std::cout << std::setw(46) << std::setfill('-') << "\n";
	std::cout << "|    INDEX |FIRST NAME| LAST NAME| NICKNAME |" << "\n";
	std::cout << std::setw(46) << std::setfill('-')  << "\n";
}

void	printIndividualContact(Contact contact, int index)
{
	std::cout << "|" << std::setfill(' ') << std::setw(10) << index;
	printInfo(contact.get_first_name());
	printInfo(contact.get_last_name());
	printInfo(contact.get_nickname());
	std::cout << "|" << std::endl;
}

void	printInfo(std::string str)
{
	int	size = str.length();

	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	if (size > 9)
	{
		std::cout << (str.substr(0, 9) + ".");
	}
	else
	{
		std::cout << str;
	}
}

// ERROR MESSAGES

void	printErrorMessage(const std::string& eMessage)
{
	std::cout << RED << "[ERROR]: " << RESET << eMessage << std::endl;
}

void	printErrorEOF(void)
{
	std::cout << RED << "\nEOF detected.\n" << RESET << "Exiting program..." << std::endl;
}

/* std::string	LMAO(int xD)
{
	std::stringstream nome;

	nome << xD;
	std::cout << nome.str() << std::endl;
} */
