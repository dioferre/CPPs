#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter( const ScalarConverter& other );
	~ScalarConverter();

	ScalarConverter& operator=( const ScalarConverter& other );

	static int	detectType( const std::string& literal );

	static bool	isChar( const std::string& literal );
	static bool	isInt( const std::string& literal );
	static bool	isDouble( const std::string& literal );
	static bool	isFloat( const std::string& literal );

	static bool	isPseudo( const std::string& literal );
	static void	handlePseudo( const std::string& literal );

	
	static void	handleChar( const std::string& literal );
	static void	handleInt( const std::string& literal );
	static void	handleDouble( const std::string& literal );
	static void	handleFloat( const std::string& literal );
	
	static void	printInfo(char c, int i, double d, float f);
	static void printErrorCase( void );
public:
	static void	convert( const std::string& literal );
};

#endif