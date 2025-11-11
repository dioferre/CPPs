/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDatabase.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:01:34 by dioferre          #+#    #+#             */
/*   Updated: 2025/11/11 18:55:35 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinDatabase.hpp"

BitcoinDatabase::BitcoinDatabase() : _data()
{
	std::ifstream	file(_dataFile);
	if (!file.is_open())
		throw CouldNotOpenDataFile();

	std::string	line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw InvalidColumnFormat();

	while(std::getline(file, line))
	{
		std::istringstream	iss(line);
		std::string			date, value;
		
		std::getline(iss, date, ',');
		std::getline(iss, value, ',');

		_data.insert(std::make_pair(Date(date), atof(value.c_str())));
	}
}

BitcoinDatabase::BitcoinDatabase( const BitcoinDatabase& other ) : _data(other._data) {}

BitcoinDatabase::~BitcoinDatabase() {}

BitcoinDatabase&	BitcoinDatabase::operator=( const BitcoinDatabase& other )
{
	if (this != &other)
	{
		_data = other._data; 
	}
	return (*this);
}

Date	BitcoinDatabase::getClosestDate( const Date& date )
{
	Date	closestDate = _data.lower_bound(date)->first;
	std::map<Date, float>::iterator it = _data.begin();

	while (it != _data.end())
	{
		if (it->first == date)
		{
			return (it->first);
		}
		else if (it->first > closestDate && it->first < date)
		{
			closestDate = it->first;
		}
		it++;
	}
	return (closestDate);
}

float	BitcoinDatabase::getValue( const Date& date )
{
	float	valueAtDate;

	valueAtDate = _data[date];
	return (valueAtDate);
}