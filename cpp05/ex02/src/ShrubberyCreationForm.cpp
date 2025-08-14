/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:05:03 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/13 19:10:53 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm( "unknown", 145, 137 ), _target("unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) :
	AForm(other.getName(), 145, 137), _target(other.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=
	( const ShrubberyCreationForm& other )
{
	if (this != &other)
	{
		_target = other.getTarget();
		AForm::operator=(other);
	}
	return (*this);
}

void	ShrubberyCreationForm::writeTree( std::ofstream& file ) const
{
		file << "        ccee88oo\n";
		file << "  C8O8O8Q8PoOb o8oo\n";
		file << " dOB69QO8PdUOpugoO9bD\n";
		file << "CgggbU8OU qOp qOdoUOdcb\n";
		file << "    6OuU  /p u gcoUodpP\n";
		file << "       \\\\\\//  /douUP\n";
		file << "         \\\\\\////\n";
		file << "          |||/\\\n";
		file << "          |||\\/\n";
		file << "          |||||\n";
		file << "    .....//||||\\....\n";
}

void	ShrubberyCreationForm::execForm() const
{
	std::ofstream	outFile;
	outFile.open((_target + "_shrubbery").c_str());

	if (outFile.is_open())
	{
		size_t	number_of_trees = 3;
		for (size_t i = 0; i < number_of_trees; i++) {
			writeTree(outFile);
			outFile << std::endl;
		}
	}
	else
	{
		throw std::runtime_error("Error opening output file");
	}
	
	outFile.close();
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return(_target);
}