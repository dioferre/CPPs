#ifndef BITCOIN_TRANSACTION_HPP
#define BITCOIN_TRANSACTION_HPP

#include "Date.hpp"
#include "BitcoinExchange.hpp"

class Date;

class BitcoinTransaction
{
private:
	Date		_date;
	const float	_value;
	const float	_amount;

	void		printError( std::string message );

	int			calculateDaysInMonth( void );
	bool		validateDate( void );
	bool		validateValue( void );
	BitcoinTransaction();
public:
	BitcoinTransaction( Date date, float value, float amount );
	BitcoinTransaction( const BitcoinTransaction& other );
	~BitcoinTransaction();

	BitcoinTransaction&	operator=( const BitcoinTransaction& other );

	void processTransaction(void);
};

#endif