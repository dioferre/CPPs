/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:36:09 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 11:12:57 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("unknown"), HP(100), EP(100), AD(30)
{
	std::cout << "<ClapTrap> default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string Name ): _name(Name), HP(100), EP(100), AD(30)
{
	std::cout << "<ClapTrap> construcor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src )
{
	*this = src;
	std::cout << "<ClapTrap> copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "<ClapTrap> destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& src)
{
	if (this != &src)
	{
		_name = src._name;
		HP = src.HP;
		EP = src.EP;
		AD = src.AD;
	}
	return (*this);
}

void	ClapTrap::attack( const std::string& target )
{
	if ( EP >= 1 && HP > 0)
	{
		std::cout << BWHITE << "<" << this->_name << "> " << RESET
					<< "attacks " << BWHITE<< "<" << target << ">" << RESET << ", "
					<< "doing " << RED << AD << RESET << " points of damage!" << std::endl;
		EP -= 1;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if ( amount <= HP && HP > 0)
	{
		std::cout << BWHITE << "<" << this->_name << "> " << RESET
			<< "takes " << RED << amount << RESET << " "
			<< "points of damage! " << std::endl;
		HP -= amount;
	}
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if ( EP > 0 && HP > 0 )
	{
		std::cout << BWHITE << "<" << this->_name << "> " << RESET
			<< "repaits itself, recovering " << GREEN << amount 
			<< RESET << " health points! " << std::endl;
		HP += amount;
	}
}

const std::string& ClapTrap::getName( void )
{
	return( _name );
}