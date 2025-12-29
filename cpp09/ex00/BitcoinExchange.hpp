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
#include <stdlib.h>

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

	BitcoinExchange();
public:
	BitcoinExchange( const std::string input_file );
	BitcoinExchange( const BitcoinExchange& other );
	~BitcoinExchange();

	BitcoinExchange&		operator=( const BitcoinExchange& other );

	void run();

	class InvalidColumnFormat : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid column format detected in file.";
		}
	};

	class CouldNotOpenFile : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: could not open file.";
		}
	};
};

#endif