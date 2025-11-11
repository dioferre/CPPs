#ifndef DATE_HPP
#define DATE_HPP

#include "BitcoinExchange.hpp"

class Date
{
private:
	int	_year;
	int	_month;
	int	_day;
public:
	Date();
	Date( std::string date );
	Date( int y, int m, int d );
	Date( const Date& other );
	~Date();

	Date&	operator=( const Date& other );
	bool	operator==( const Date& other ) const;
	bool	operator<( const Date& other ) const ;
	bool	operator>( const Date& other ) const ;
	
	
	int	getYear( void ) const ;
	int	getMonth( void ) const ;
	int	getDay( void ) const ;
};

std::ostream&	operator<<(std::ostream& os, const Date& date);


#endif