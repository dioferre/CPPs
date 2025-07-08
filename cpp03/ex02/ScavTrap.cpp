/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:38:00 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 13:39:02 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string Name ) : ClapTrap(Name)
{
	std::cout << "<ScavTrap> constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap(src)
{
	std::cout << "<ScavTrap> copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "<ScavTrap> destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& src )
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

void	ScavTrap::attack( const std::string& target )
{
	if ( EP >= 1 && HP > 0)
	{
		std::cout << BWHITE << "<" << this->_name << "> " << RESET
					<< "with an astonishing attack power of " << RED << AD << RESET << ","
					<< " attacks " << BWHITE<< "<" << target << ">" << RESET << "!\n"
					<< "However it slips and misses the attack, how embarassing!" << std::endl;
	}
}

void	ScavTrap::guardGate( void )
{
	if ( HP > 0 )
	{
		std::cout << BWHITE << "<" << this->_name << "> " << RESET
					<< "is now guarding the gate! "
					<< "Whatever that means..." << std::endl;
	}
}