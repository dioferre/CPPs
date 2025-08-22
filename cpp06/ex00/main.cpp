
#include "ScalarConverter.hpp"


// needs to be in canonincal form, have fun idiot lmaooo

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "program only accepts one argument!" << std::endl;
	}
	else
	{
		ScalarConverter::convert(argv[1]);
	}
	return (0);
}