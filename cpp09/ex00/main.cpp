/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:04:24 by dioferre          #+#    #+#             */
/*   Updated: 2025/12/29 16:42:49 by dioferre         ###   ########.fr       */
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
	
	BitcoinExchange	BTE(argv[1]);
	BTE.run();
	
	return (0);
}