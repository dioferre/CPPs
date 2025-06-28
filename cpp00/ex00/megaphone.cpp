 #include <iostream>

void	printArg(char *arg)
{
	while (*arg)
	{
		if (std::isalpha(*arg))
		{
			std::cout << (char)std::toupper(*arg);
		}
		else
		{
			std::cout << *arg;
		}
		arg++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		argv++;
		while (*argv)
		{
			printArg(*argv);
			argv++;
		}
		std::cout << std::endl;
	}
	return (0);
}
