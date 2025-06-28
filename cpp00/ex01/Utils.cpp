/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:58:23 by dioferre          #+#    #+#             */
/*   Updated: 2025/05/09 17:46:36 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

bool	isPrintableStr(std::string& str)
{
	size_t	i = 0;

	while (str[i])
	{
		if (!isprint(str[i++]))
			return (false);
	}
	return (true);
}

bool	isAllDigitStr(std::string& str)
{
	size_t	i = 0;

	while (str[i])
	{
		if (!isdigit(str[i++]))
			return (false);
	}
	return (true);
}

bool	hasOnlySpaces(std::string& str)
{
	size_t	i = 0;

	while (str[i])
	{
		if ((str[i++]) != ' ')
			return (false);
	}
	return (true);
}


std::string	readInput(const std::string& Message)
{
	std::string	input = "";

	while (1)
	{
		std::cout << Message;
 		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof() && Message == "Select a contact index: ")
			{
				std::cin.clear();
				return (input);
			}
			else
			{
				printErrorEOF();
				exit (1);
			}
		}
		else if (input.empty())
		{
			printErrorMessage("This field can't be empty!");
		}
		else if (!isPrintableStr(input))
		{
			printErrorMessage("Bad characters detected!");
		}
		else if (hasOnlySpaces(input))
		{
			printErrorMessage("String can't have only spaces!");
		}
		else if (Message == "Phone number: " || Message == "Select a contact index: ")
		{
			if (!isAllDigitStr(input))
			{
				printErrorMessage("This field can only have digits!");
			}
			else if (Message == "Phone number: " && input.length() != 9)
			{
				printErrorMessage("A phone number must contain 9 digits!");
			}
			else
				break ;
		}
		else
			break ;
	}
	return (input);
}

