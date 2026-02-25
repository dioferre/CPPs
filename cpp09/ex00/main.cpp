/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:04:24 by dioferre          #+#    #+#             */
/*   Updated: 2026/02/23 09:53:50 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "BitcoinDatabase.hpp"
#include "BitcoinTransaction.hpp"
#include "Date.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "ERROR: Invalid number of arguments!" << std::endl;
		return (1);
	}
	
	try 
	{
		BitcoinExchange	BTE(argv[1]);
		BTE.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << "[ERROR]: " << e.what() << std::endl;
	}
	
	return (0);
}