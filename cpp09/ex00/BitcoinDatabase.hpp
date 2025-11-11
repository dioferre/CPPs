#ifndef BITCOIN_DATABASE_HPP
#define BITCOIN_DATABASE_HPP

#include "Date.hpp"

class Date;

class BitcoinDatabase
{
private:
	std::map<Date, float>	_data;

	const std::string		_dataFile = "data.csv";

public:
	BitcoinDatabase();
	BitcoinDatabase( const BitcoinDatabase& other ); 
	~BitcoinDatabase();
	
	BitcoinDatabase&	operator=( const BitcoinDatabase& other );
	
	Date	getClosestDate( const Date &date );
	float	getValue( const Date &date );
};

#endif