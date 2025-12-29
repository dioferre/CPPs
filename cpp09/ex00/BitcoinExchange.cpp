/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:41:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/12/29 16:40:12 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const std::string input_file ) :
	_database(), _input_file(input_file)
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) 
{
	(void) other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other ) 
{
	if (this != &other)
	{}
	return (*this);
}

// IMPORTANT:
// Will need to change the behavior of transactions because of the map behvior
// and container limitaiton;
// Instead of building and storing the individual transactions, I'll simply execute them as I go.
void	BitcoinExchange::run()
{
	std::ifstream	file(_input_file.c_str());
	if (!file.is_open())
		throw CouldNotOpenFile();
	
	std::string	line;
	std::getline(file, line);
	if (line != "date | value")
		throw InvalidColumnFormat();

	while(std::getline(file, line))
	{
		std::istringstream	iss(line);
		std::string date_str, amount_str;
		std::getline(iss, date_str, '|');
		std::getline(iss, amount_str, '|');

		if (amount_str.length() > 0)
			date_str.erase(date_str.length() - 1);
		amount_str.erase(0, 1);

		Date	closestDate = _database.getClosestDate(Date(date_str));
		float	exchange_rate = _database.getValue(closestDate);
		float	amount = atof(amount_str.c_str());

		BitcoinTransaction	current_transction(Date(date_str), exchange_rate, amount);
		current_transction.processTransaction();
	}
}
