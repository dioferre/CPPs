/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinTransaction.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:59:03 by dioferre          #+#    #+#             */
/*   Updated: 2025/12/29 16:37:08 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinTransaction.hpp"

BitcoinTransaction::BitcoinTransaction() : _date(Date()), _exchange_rate(0), _amount(0) {}

BitcoinTransaction::BitcoinTransaction( Date date, float exchange_rate, float amount ) : 
	_date(date), _exchange_rate(exchange_rate), _amount(amount) {}

BitcoinTransaction::BitcoinTransaction( const BitcoinTransaction& other ) :
	_date(other._date), _exchange_rate(other._exchange_rate), _amount(other._amount) {}

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
		std::cout << "Error: bad input => " << _date << std::endl;
	}
	else
	{
		std::cout << "Error: " << message << "." << std::endl;
	}
}

bool	BitcoinTransaction::validateAmount( void ) 
{
	if (_amount < 0)
	{
		printError("not a positive number");
		return (true);
	}
	else if (_amount > 1000)
	{
		printError("too large a number");
		return (true);
	}
	return (false);
}

bool	BitcoinTransaction::validateDate( void ) 
{
	if ((_date.getYear() < 2009 || _date.getMonth() < 1 || _date.getMonth() > 12 
		|| _date.getDay() < 1 || _date.getDay() > 31) // checking if date exchange_rates are valid
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
	if (validateAmount() || validateDate())
		return ;

	std::cout << _date << " => " << _amount << " = " << float(_exchange_rate * _amount) << std::endl;
}