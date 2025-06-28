/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:58:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/05/09 17:35:16 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	input;

	std::cout << "\n\n" << std::setw(21) <<  std::setfill(' ')
				<< GREEN << "[ Welcome to Phonebook ]" << RESET << "\n";
	while (1)
	{
		std::cout << "Select one of the available commands: ADD, SEARCH, EXIT" << std::endl;
		if (!getline(std::cin, input) || std::cin.eof())
		{
			printErrorEOF();
			std::cin.clear();
			return (1);
		}
		else if (input == "ADD")
		{
			if (phonebook.Add())
			{
				printErrorEOF();
				return (1);
			}
		}
		else if (input == "SEARCH")
		{
			if (phonebook.Search())
			{
				printErrorEOF();
				return (1);
			}
		}
		else if (input == "EXIT")
		{
			break;
		}
		else
		{
			printErrorMessage("Invalid Command!");
		}
	}
	return (0);
}
