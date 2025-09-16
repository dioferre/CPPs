/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 08:55:58 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/15 09:15:03 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	add_one_int(int &nr)
{
	nr += 1;
}

void	add_one_char(char &c)
{
	c += 1;
}

void	int_array_test(void)
{
	int	arr[5] = {1,2,3,4,5};
	
	std::cout << "Testing with an int array: " << std::endl;

	std::cout << "before: ";
	for (int i = 0; i < 4; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	::iter(arr, 5, add_one_int);

	std::cout << "after: ";
	for (int i = 0; i < 4; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void	char_array_test(void)
{
	char	arr[6] = {'b','a','n','a','n','a'};

	std::cout << "Testing with a char array: " << std::endl;

	std::cout << "before: ";
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	::iter(arr, 6, add_one_char);

	std::cout << "after: ";
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int	main(void)
{
	int_array_test();
	char_array_test();
	
	return (0);
}