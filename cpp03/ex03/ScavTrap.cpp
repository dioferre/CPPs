/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:20:09 by dioferre          #+#    #+#             */
/*   Updated: 2025/06/28 15:13:58 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	HP = 100;
	EP = 50;
	AD = 20;
}


ScavTrap::ScavTrap( std::string Name ) : ClapTrap(Name)
{
	std::cout << BWHITE << "<ScavTrap>"
				<< GREEN " Constructor" << RESET
				<< " called." << std::endl;
	HP = 100;
	EP = 50;
	AD = 20;
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap(src.getName())
{
}

ScavTrap::~ScavTrap()
{
	std::cout << BWHITE << "<ScavTrap>"
				<< RED " Destructor" << RESET
				<< " called." << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& src)
{
	if (this != &src)
	{
		_name = src.getName();
		HP = src.getHP();
		EP = src.getEP();
		AD = src.getAD();
	}
	return (*this);
}

void	ScavTrap::attack( const std::string& target )
{
	std::cout << BWHITE << "<" << this->_name << "> " << RESET
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