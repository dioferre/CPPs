/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:21:24 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/16 13:41:25 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"


int	main(void)
{
	int a=1, b=2, c=3;
	
	char c1='a',c2='b',c3='c';

	Array<char>	empty;
	Array<char>	char_arr(3);
	Array<int>	int_arr(3);

	char_arr[0] = c1;
	char_arr[1] = c2;
	char_arr[2] = c3;

	int_arr[0] = a;
	int_arr[1] = b;
	int_arr[2] = c;

	std::cout << "Char arr: ";
	for (unsigned int i = 0; i < char_arr.size(); i++) {
		std::cout << char_arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Int arr: ";
	for (unsigned int i = 0; i < int_arr.size(); i++) {
		std::cout << int_arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Empty arr: ";
	for (unsigned int i = 0; i < empty.size(); i++) {
		std::cout << empty[i] << " ";
	}
	std::cout << std::endl;
}
