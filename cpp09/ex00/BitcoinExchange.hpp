#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <string>

#include "Date.hpp"
#include "BitcoinTransaction.hpp"
#include "BitcoinDatabase.hpp"

class Date;
class BitcoinTransaction;
class BitcoinDatabase;

class BitcoinExchange
{
private:
	BitcoinDatabase			_database;

	const std::string		_input_file;

	// Helper
	std::string trim(const std::string& s);

	BitcoinExchange();
public:
	BitcoinExchange( const std::string input_file );
	BitcoinExchange( const BitcoinExchange& other );
	~BitcoinExchange();

	BitcoinExchange&		operator=( const BitcoinExchange& other );

	void run();

};

#endif