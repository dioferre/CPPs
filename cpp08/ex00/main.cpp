/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:02:02 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/16 14:17:12 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	{	
		std::vector<int> vec(3);
		for (int i = 0; i < 3; i++)
			vec.push_back(i);
		
		std::cout << "Vector:" << std::endl;
		try
		{
			std::cout << "Finding 2: " << easyfind(vec, 2) << std::endl;
			std::cout << "Finding 5: " << easyfind(vec, 5) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		std::list<int> lst(3);
		for (int i = 0; i < 7; i++)
			lst.push_back(i);
		
		std::cout << "List:" << std::endl;
		try
		{
			std::cout << "Finding 3: " << easyfind(lst, 3) << std::endl;
			std::cout << "Finding 5: " << easyfind(lst, 5) << std::endl;
			std::cout << "Finding 42: " << easyfind(lst, 42) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}