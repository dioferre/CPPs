/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:14:31 by dioferre          #+#    #+#             */
/*   Updated: 2025/12/29 19:10:40 by dioferre         ###   ########.fr       */
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
			_expression.push(atoi(current_token.c_str()));
	}
	
	// Need to verify this.
	std::cout << _expression.top() << std::endl;
	_expression.pop();
}

RPN::~RPN() {}

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
		
	for (char c : token)
	{
		if (!isdigit(c))
			return (false);
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
			if (num2 == 0) throw std::runtime_error("Error: division by zero");
			result = num1 / num2;
			break;
		default: throw std::invalid_argument("Error: unknown operator"); // should never happen lel
	}
	_expression.push(result);
}
