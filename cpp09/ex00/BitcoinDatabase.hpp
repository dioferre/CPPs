#ifndef BITCOIN_DATABASE_HPP
#define BITCOIN_DATABASE_HPP

#include "Date.hpp"
#include "Exceptions.hpp"
#include <cstdlib>
#include <map>

class Date;

class BitcoinDatabase
{
private:
	std::map<Date, float>		_data;

	static const std::string	_dataFile;
public:
	BitcoinDatabase();
	BitcoinDatabase( const BitcoinDatabase& other ); 
	~BitcoinDatabase();
	
	BitcoinDatabase&	operator=( const BitcoinDatabase& other );
	
	Date	getClosestDate( const Date &date );
	float	getValue( const Date &date );
};

#endif