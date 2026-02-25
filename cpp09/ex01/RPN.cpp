/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:14:31 by dioferre          #+#    #+#             */
/*   Updated: 2026/02/25 09:11:31 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( const std::string expression )
{
	std::stringstream	ss(expression);
	std::string			current_token;


	while(ss >> current_token)
	{
		if (!isValidToken(current_token))
		{
			std::cerr 
			<< "[ERROR]: Invalid token => " << current_token
			<< std::endl;
			return ;
		}
		else if (!isdigit(*current_token.c_str()))
			executeOperation(*current_token.c_str());
		else
			_expression.push(std::atoi(current_token.c_str()));
	}
	
	// Need to verify this.
	std::cout << _expression.top() << std::endl;
	_expression.pop();
}

RPN::RPN(const RPN& other) { *this = other; }

RPN::~RPN() {}

RPN&	RPN::operator=( const RPN& other )
{
	if (this != &other)
	{}

	return (*this);
}

bool	RPN::isOperation( const char c ) const
{
	if ( c == '+' || c == '-' || c == '*' || c == '/' )
		return (true);
	return (false);
}

bool	RPN::isValidToken( const std::string& token ) const
{
	if (token.empty())
		return (false);
	
	if (token.length() == 1 && isOperation(token[0]))
		return (true);
		
	for (std::string::size_type i = 0; i < token.length(); ++i)
	{
		if (!isdigit(static_cast<unsigned char>(token[i])))
			return false;
	}
	
	return (true);
}

void	RPN::executeOperation(const char c)
{
	if (_expression.size() < 2)
		throw std::runtime_error("Error: insufficient operands");

	int num2 = _expression.top(); // Right operand
	_expression.pop();

	int num1 = _expression.top(); // Left operand
	_expression.pop();

	int result;
	switch (c)
	{
		case '+': result = num1 + num2; break;
		case '-': result = num1 - num2; break;
		case '*': result = num1 * num2; break;
		case '/':
			if (num2 == 0) throw std::runtime_error("division by zero");
			result = num1 / num2;
			break;
		default: throw std::invalid_argument("unknown operator"); // should never happen lel
	}
	_expression.push(result);
}
