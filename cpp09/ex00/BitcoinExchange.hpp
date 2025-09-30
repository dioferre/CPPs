#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class Date
{
private:
	const int	_year;
	const int	_month;
	const int	_day;
public:
	Date();
	Date( int y, int m, int d );
	Date( const Date& other );
	~Date();

	Date&	operator=( const Date& other );

	int	getYear( void );
	int	getMonth( void );
	int	getDay( void );
};

class BitcoinTransaction
{
private:
	Date		_date;
	const float	_value;

	void		printError( std::string message );

	int			calculateDaysInMonth( void );
public:
	BitcoinTransaction();
	BitcoinTransaction( Date date, float value );
	BitcoinTransaction( const BitcoinTransaction& other );
	~BitcoinTransaction();

	BitcoinTransaction&	operator=( const BitcoinTransaction& other );

	void	validateDate( void );
	void	validateValue( void );
};

class BitcoinDatabase
{
private:
	BitcoinDatabase&	operator=( const BitcoinDatabase& other );

	std::map<Date, int>	_database;

	Date	getClosestDate( const Date &date ) const;
public:
	BitcoinDatabase();
	BitcoinDatabase( const BitcoinDatabase& other ); 
	~BitcoinDatabase();


	float	getValue( const Date &date ) const;
};

#endif