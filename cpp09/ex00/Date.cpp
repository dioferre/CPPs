/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:57:57 by dioferre          #+#    #+#             */
/*   Updated: 2025/12/29 16:15:51 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() : _year(2000), _month(1), _day(1) {}

Date::Date( std::string date )
{
	std::stringstream	ss(date);
	char	sep;

	ss >> _year >> sep >> _month >> sep >> _day;
}

Date::Date( int y, int m, int d ) : _year(y), _month(m), _day(d) {}

Date::Date( const Date& other ) : _year(other._year), _month(other._month),
_day(other._day) {}

Date::~Date() {}


Date&	Date::operator=( const Date& other )
{
	if (this != &other) 
	{
		_year = other._year;
		_month = other._month;
		_day = other._day;
	}
	return (*this);
}

bool	Date::operator==( const Date& other ) const
{
	if (_year == other._year && _month == other._month && _day == other._day)
		return (true);
	return (false);
}

bool	Date::operator<( const Date& other ) const
{
	if (_year != other._year)
		return (_year < other._year);
	else if (_month != other._month)
		return (_month < other._month);
	return (_day < other._day);
}

bool	Date::operator>( const Date& other ) const
{
	if (_year != other._year)
		return (_year > other._year);
	else if (_month != other._month)
		return (_month > other._month);
	return (_day > other._day);
}

int	Date::getYear( void ) const { return (_year); }

int	Date::getMonth( void ) const { return (_month); }

int	Date::getDay( void ) const { return (_day); }

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	// Save the current fill character to restore it later (optional but good practice)
	char prevFill = os.fill();

	os << date.getYear() << '-'
		<< std::setfill('0') << std::setw(2) << date.getMonth() << '-'
		<< std::setfill('0') << std::setw(2) << date.getDay();

	// Restore the original fill character
	os.fill(prevFill);

	return os;
}