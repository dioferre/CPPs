/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:41:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/30 15:31:59 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// =================================   DATE    =================================

Date::Date() : _year(2000), _month(1), _day(1) {}

Date::Date( int y, int m, int d ) : _year(y), _month(m), _day(d) {}

Date::Date( const Date& other ) : _year(other._year), _month(other._month),
_day(other._day) {}

Date::~Date() {}


Date&	Date::operator=( const Date& other )
{
	if (this != &other) {}
	
	return (*this);
}

int	Date::getYear( void ) { return (_year); }

int	Date::getMonth( void ) { return (_month); }

int	Date::getDay( void ) { return (_day); }

// ================================ TRANSACTION ================================

BitcoinTransaction::BitcoinTransaction() : _date(Date()), _value(0) {}

BitcoinTransaction::BitcoinTransaction( Date date, float value ) : 
	_date(date), _value(value) {}

BitcoinTransaction::BitcoinTransaction( const BitcoinTransaction& other ) :
	_date(other._date), _value(other._value) {}

BitcoinTransaction::~BitcoinTransaction() {}


BitcoinTransaction&	BitcoinTransaction::operator=
	( const BitcoinTransaction& other )
{
	if (this != &other) {}
	
	return (*this);
}

int		BitcoinTransaction::calculateDaysInMonth( void )
{
	int daysInMonth;

	if (_date.getMonth() == 2)
	{
		if ((_date.getYear() % 400 == 0) || 
			(_date.getYear() % 4 == 0 && _date.getYear() % 100 != 0))
		{
			daysInMonth = 29;
		}
		else
			daysInMonth = 28;
	}
	else if (_date.getMonth() == 4 || _date.getMonth() == 6 
		|| _date.getMonth() == 9 || _date.getMonth() == 11) 
	{
		daysInMonth = 30;
	}
	else 
	{
		daysInMonth = 31;
	}
	return( daysInMonth );
}

void	BitcoinTransaction::printError( std::string message)
{
	if (message == "invalid date") 
	{
		std::cout << "Error: bad input => " << _date.getYear()
			<< "-" << _date.getMonth() << "-" << _date.getDay()
			<< std::endl;
	}
	else
	{
		std::cout << "Error: " << message << "." << std::endl;
	}
}

void	BitcoinTransaction::validateValue( void ) 
{
	if (_value < 0)
		printError("not a positive number");
	else if (_value > 1000)
		printError("too large a number");
	else
		return;
}

void	BitcoinTransaction::validateDate( void ) 
{
	// Working on this, need to make it print error instead lol
	if ((_date.getYear() < 2009 || _date.getMonth() < 1 || _date.getMonth() > 12 
		|| _date.getDay() < 1 || _date.getDay() > 31) // checking if date values are valid
		|| (_date.getDay() > calculateDaysInMonth()) // checking if the day doesn't exceed the month's total days
		|| (_date.getYear() == 2009 && (_date.getMonth() == 1 && _date.getDay() < 3))) // checking if date isn't prior to creation of BTC
	{
		printError("invalid date");
	}
	return ;
}

// ================================= DATABASE ==================================


BitcoinDatabase::BitcoinDatabase() : _database() {}

BitcoinDatabase::BitcoinDatabase( const BitcoinDatabase& other ) : _database(other._database) {}

BitcoinDatabase::~BitcoinDatabase() {}

BitcoinDatabase&	BitcoinDatabase::operator=( const BitcoinDatabase& other )
{
	if (this != &other)
	{
		_database = other._database; 
	}
	return (*this);
}

Date	BitcoinDatabase::getClosestDate( const Date& date ) const
{
	
}

float	BitcoinDatabase::getValue( const Date& date ) const
{
	return ( );
}