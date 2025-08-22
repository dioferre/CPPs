/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:30:06 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/15 13:45:52 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ===========================================

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter& other) { (void) other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other) 
{
	if (this != &other)
	{

	}
	return (*this);
}

// ===========================================

bool	ScalarConverter::isChar( const std::string& literal )
{
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (true);
	return (false);
}
bool	ScalarConverter::isInt( const std::string& literal )
{
	size_t	i = 0;

	if ((literal[0] == '-' || literal[0] == '+') && literal.length() != 1)
		i++;
	
	while (i < literal.length())
	{
		if (!isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}
bool	ScalarConverter::isDouble( const std::string& literal )
{
	size_t	i = 0;
	
	if (literal[i] == '-' || literal[i] == '+')
	{
		i++;
		if (!isdigit(literal[i]))
			return (false);
	}
	
	int	dots = 0;

	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			dots++;
			if (dots > 1)
				return (false);
		}
		else if (!isdigit(literal[i]))
		{
			return (false);
		}
		i++;
	}
	
	return (true);
}
bool	ScalarConverter::isFloat( const std::string& literal )
{
	if (*(literal.end() - 1) != 'f')
		return (false);

	size_t	i = 0;
	
	if (literal[i] == '-' || literal[i] == '+')
	{
		i++;
		if (!isdigit(literal[i]))
			return (false);
	}

	int	dots = 0;

	while (i < literal.length() - 1)
	{
		if (literal[i] == '.')
		{
			dots++;
			if (dots > 1)
				return (false);
		}
		else if (!isdigit(literal[i]))
		{
			return (false);
		}
		i++;
	}

	return (true);
}

bool	ScalarConverter::isPseudo( const std::string& literal )
{
	if (literal == "+inff" || literal == "+inf" ||
		literal == "-inff" || literal == "-inf" ||
		literal == "nan" || literal == "nanf")
		return true;
	return false;
}

int ScalarConverter::detectType( const std::string& literal )
{
	int	type = 0;
	typedef bool (*isType)(const std::string&);
	
	static isType type_functions[4] = { isChar, isInt, isDouble, isFloat };
	for (int i = 0; i < 4; i++)
	{
		if (type_functions[i](literal))
		{
			type = i + 1;
			break;
		}
	}
	return (type);
}

// ==========================================================

void	ScalarConverter::printInfo( char c, int i, double d, float f )
{
	std::cout << "Char: ";
	if (isprint(c))
	{
		std::cout << c << std::endl;
	}
	else
	{
		std::cout << "Non Displayable." << std::endl;
	}

	std::cout << "Int: " << i << std::endl;

	std::cout << "Double: " << d;
	if (d == static_cast<int>(d))
	{
		std::cout << ".0";
	}
	std::cout << std::endl;
	
	std::cout << "Float: " << f;
	if (f == static_cast<int>(f))
	{
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void	ScalarConverter::printErrorCase( void )
{
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Double: Impossible" << std::endl;
	std::cout << "Float: Impossible" << std::endl;
}

void	ScalarConverter::handleChar( const std::string& literal )
{
	char	c;
	int		i;
	double	d;
	float	f;

	c = literal[1];
	i = static_cast<int>(c);
	d = static_cast<double>(c);
	f = static_cast<float>(c);

	printInfo(c, i, d ,f);
}

void	ScalarConverter::handleInt( const std::string& literal )
{
	errno = 0;
	long	l = strtol(literal.c_str(), NULL, 10);

	if (errno || l > INT_MAX || l < INT_MIN)
	{
		printErrorCase();
		return ;
	}

	char	c = static_cast<char>(l);
	int		i = static_cast<int>(l);
	double	d = static_cast<double>(l);
	float	f = static_cast<float>(l);

	printInfo(c, i, d ,f);
}
void	ScalarConverter::handleDouble( const std::string& literal )
{
	errno = 0;
	double	d = strtod(literal.c_str(), NULL);

	if (errno)
	{
		printErrorCase();
		return ;
	}

	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	printInfo(c, i, d ,f);
}
void	ScalarConverter::handleFloat( const std::string& literal )
{
	errno = 0;
	float	f = strtof(literal.c_str(), NULL);

	if (errno)
	{
		printErrorCase();
		return ;
	}

	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<float>(f);

	printInfo(c, i, d ,f);
}

void	ScalarConverter::handlePseudo( const std::string& literal )
{
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;

	if (literal == "+inff" || literal == "+inf")
	{
		std::cout << "Float: +inff" << std::endl;
		std::cout << "Double: +inf" << std::endl;
	}
	else if (literal == "-inff" || literal == "-inf")   
	{
		std::cout << "Float: -inff" << std::endl;
		std::cout << "Double: -inf" << std::endl;
	}
	else if (literal == "nan" || literal == "nanf")
	{
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	}
	return ;
}

// ==========================================================

void	ScalarConverter::convert( const std::string& literal )
{
	if (literal.length() == 0)
	{
		std::cout << "Error: empty!" << std::endl;
		return;
	}
	if (isPseudo(literal))
	{
		handlePseudo(literal);
		return ;
	}
	int type = detectType(literal);
	if (!type)
	{
		std::cout << "Error: invalid type!" << std::endl;
		return ;
	}

	enum types {CHR = 1, INT = 2, DBL = 3, FLT = 4};

	switch (type)
	{
	case CHR:
		handleChar(literal);
		return;
	case INT:
		handleInt(literal);
		return;
	case DBL:
		handleDouble(literal);
		return;
	case FLT:
		handleFloat(literal);
		return;
	default:
		std::cerr << "Error: invalid input!" << std::endl;
		return ;
	}
}