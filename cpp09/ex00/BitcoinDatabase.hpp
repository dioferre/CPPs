#ifndef BITCOIN_DATABASE_HPP
#define BITCOIN_DATABASE_HPP

#include "Date.hpp"
#include <map>
#include <stdlib.h>

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


	class InvalidColumnFormat : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid column format detected in file.";
		}
	};

	class CouldNotOpenDataFile : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: could not open file.";
		}
	};
};

#endif