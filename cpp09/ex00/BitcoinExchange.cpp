/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:41:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/11/11 18:41:52 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const std::string input_file ) :
	_database()
{
	buildTransactions(input_file);
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other ) {}

void	BitcoinExchange::buildTransactions( const std::string input_file )
{
	std::ifstream	file(input_file);
	if (!file.is_open())
		throw CouldNotOpenFile();
	
	std::string	line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw InvalidColumnFormat();

	while(std::getline(file, line))
	{
		std::istringstream	iss(line);
		std::string date, value;
		std::getline(iss, date, '|');
		std::getline(iss, value, '|');

		date.erase(date.length() - 1);
		value.erase(0);

		_transactions.insert(std::make_pair(Date(date), atof(value.c_str())));
	}
}

void	BitcoinExchange::executeTransactions()
{
	for (std::map<Date, float>::const_iterator it = _transactions.begin(); 
		it != _transactions.end(); ++it)
	{
		Date	closestDate = _database.getClosestDate(it->first);
		float	value = _database.getValue(closestDate);
		float	amount = it->second;

		BitcoinTransaction	current_transction(closestDate, value, amount);
		current_transction.processTransaction();
	}


}