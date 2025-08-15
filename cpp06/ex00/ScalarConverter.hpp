#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter(/* args */);
	~ScalarConverter();

	static const int	detectType( const std::string& literal );

	static int	isChar( const std::string& literal );
	static int	isInt( const std::string& literal );
	static int	isDouble( const std::string& literal );
	static int	isFloat( const std::string& literal );

	static void	handleChar( const std::string& literal );
	static void	handleInt( const std::string& literal );
	static void	handleDouble( const std::string& literal );
	static void	handleFloat( const std::string& literal );

	static void	printInfo(char c, int i, double d, float f);
public:
	static void	convert( const std::string& literal );
};

#endif