#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
# include <fstream>
# include <sstream>
#include <map>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "Date.hpp"
#include "BitcoinTransaction.hpp"
#include "BitcoinDatabase.hpp"

class Date;
class BitcoinTransaction;
class BitcoinDatabase;

class BitcoinExchange
{
private:
	std::map<Date, float>	_transactions;


	BitcoinDatabase			_database;

	void					buildTransactions( const std::string input_file );

	BitcoinExchange();
public:
	BitcoinExchange( const std::string input_file );
	BitcoinExchange( const BitcoinExchange& other );
	~BitcoinExchange();

	BitcoinExchange&		operator=( const BitcoinExchange& other );

	void	executeTransactions();
};

#endif