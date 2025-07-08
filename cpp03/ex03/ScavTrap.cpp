/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:20:09 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 11:20:32 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	HP = 100;
	EP = 50;
	AD = 20;
	std::cout << "<ScavTrap> default constructor called" << std::endl;
}


ScavTrap::ScavTrap( std::string Name ) : ClapTrap(Name)
{
	HP = 100;
	EP = 50;
	AD = 20;
	std::cout << "<ScavTrap> constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap(src)
{
	std::cout << "<FragTrap> copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "<ScavTrap> destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

void	ScavTrap::attack( const std::string& target )
{
	std::cout << BWHITE << "<" << this->getName() << "> " << RESET
				<< "with an astonishing attack power of " << RED << AD << RESET << ","
				<< " attacks " << BWHITE<< "<" << target << ">" << RESET << "!\n"
				<< "However it slips and misses the attack, how embarassing!" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << BWHITE << "<" << this->_name << "> " << RESET
				<< "is now guarding the gate! "
				<< "Whatever that means..." << std::endl;
}