#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>

class Date
{
public:
	Date();
	Date( int y, int m, int d );
	Date( const Date& other );
	~Date();

	Date&	operator=( const Date& other );

	int	year_;
	int	month_;
	int	day_;
};


#endif