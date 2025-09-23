#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept> 
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
private:
	std::vector<int>	_nrs;
	unsigned int		max_size;
public:
	Span();
	Span( unsigned int N );
	Span( const Span& other);
	~Span();

	Span&	operator=( const Span& other );

	void	addNumber( int nr );
	void	addNumberRange( int start, int end );

	int		shortestSpan(void);
	int		longestSpan(void);
} ;

#endif