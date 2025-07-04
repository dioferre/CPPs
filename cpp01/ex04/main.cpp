/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:56:52 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/04 16:10:11 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void	printError( std::string str )
{
	std::cerr << "[Error]: " << str << std::endl;
}


std::string	replaceString( std::string line, std::string s1, std::string s2 )
{
	std::string	new_line;
	size_t		pos = 0;
	size_t		prev = 0;


	while ( (pos = line.find(s1, prev)) != line.npos ) {
		new_line += line.substr(prev, pos - prev);
		new_line += s2;
		prev = pos + s1.length();
	}

	new_line += line.substr(prev);
	return (new_line);
}

int	openFiles( std::ifstream *infile, std::ofstream *outfile, char **argv )
{
	std::string	inName;
	std::string	outName;


	inName = argv[1];
	outName = outName + argv[1] + ".replace";

	(*infile).open(inName.c_str(), std::fstream::in);
	if (!(*infile))
	{
		printError("Infile error!");
		(*infile).close();
		return (1);
	}

	(*outfile).open(outName.c_str(), std::fstream::out);
	if (!(*outfile))
	{
		printError("outfile error!");
		(*infile).close();
		(*outfile).close();
		return (1);
	}

	return (0);
}

int	main( int argc, char **argv )
{
	std::ifstream	infile;
	std::ofstream	outfile;

	std::string		line;

	if (!*argv[2])
	{
		printError("Cannot replace NULL character.");
		return (1);
	}
	if (argc != 4)
	{
		printError("Program takes 3 arguments.");
		return (1);
	}

	if ( openFiles(&infile, &outfile, argv) )
		return (1);

	bool	isFirstLine = true;
	while ( std::getline(infile, line) ) {
		if (!isFirstLine)
			outfile << '\n';
		else
			isFirstLine = false;
		outfile << replaceString(line, argv[2], argv[3]);
	}

	infile.close();
	outfile.close();
	return (0);
}
