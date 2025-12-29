#ifndef RPN_HPP
#define RPN_HPP

#include <iomanip>
#include <stack>
#include <list>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

class RPN
{
private:
	/* data */
	
	std::stack<int>	_expression;

	bool	isValidToken( const std::string& token ) const;
	bool	isOperation( const char c ) const;

	void	executeOperation( const char c );

	RPN();
public:
	RPN( const std::string expression );
	~RPN();
};

#endif