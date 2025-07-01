/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:50:18 by dioferre          #+#    #+#             */
/*   Updated: 2025/06/28 15:42:42 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "------------------\n";
	std::cout << "Memory Addresses: \n";
	std::cout << "string:    " << &string << "\n";
	std::cout << "stringPTR: " << &stringPTR << "\n";
	std::cout << "stringREF: " << &stringREF << "\n";
	std::cout << "------------------\n";
	std::cout << "Values: \n";
	std::cout << "string variable:         " << string << "\n";
	std::cout << "pointed to by stringPTR: " << stringPTR << "\n";
	std::cout << "pointed to by stringREF: " << stringREF << "\n";
	std::cout << std::endl;

	return (0);
}
