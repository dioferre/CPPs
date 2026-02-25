#ifndef RPN_HPP
#define RPN_HPP

#include <iomanip>
#include <stack>
#include <list>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <cstdlib>

class RPN
{
private:
	std::stack<int>	_expression;

	bool	isValidToken( const std::string& token ) const;
	bool	isOperation( const char c ) const;

	void	executeOperation( const char c );

	RPN();
	RPN( const RPN& other );
	RPN&	operator=(const RPN& other);
public:
	RPN( const std::string expression );
	~RPN();
};

#endif