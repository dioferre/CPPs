/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinTransaction.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:59:03 by dioferre          #+#    #+#             */
/*   Updated: 2025/11/11 18:55:29 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinTransaction.hpp"

BitcoinTransaction::BitcoinTransaction() : _date(Date()), _value(0) {}

BitcoinTransaction::BitcoinTransaction( Date date, float value, float amount ) : 
	_date(date), _value(value), _amount(amount) {}

BitcoinTransaction::BitcoinTransaction( const BitcoinTransaction& other ) :
	_date(other._date), _value(other._value), _amount(other._amount) {}

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

bool	BitcoinTransaction::validateValue( void ) 
{
	if (_value < 0)
	{
		printError("not a positive number");
		return (true);
	}
	else if (_value > 1000)
	{
		printError("too large a number");
		return (true);
	}
	return (false);
}

bool	BitcoinTransaction::validateDate( void ) 
{
	if ((_date.getYear() < 2009 || _date.getMonth() < 1 || _date.getMonth() > 12 
		|| _date.getDay() < 1 || _date.getDay() > 31) // checking if date values are valid
		|| (_date.getDay() > calculateDaysInMonth()) // checking if the day doesn't exceed the month's total days
		|| (_date.getYear() == 2009 && (_date.getMonth() == 1 && _date.getDay() < 3))) // checking if date isn't prior to creation of BTC
	{
		printError("invalid date");
		return (true);
	}
	return (false);
}

void	BitcoinTransaction::processTransaction()
{
	if (validateValue() || validateDate())
		return ;

	std::cout << _date << " => " << _value << " = " << (_value * _amount) << std::endl;
}