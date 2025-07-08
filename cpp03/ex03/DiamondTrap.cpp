/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:04:26 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 11:16:32 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() :
		ClapTrap("unknown_clap_name"), 
		ScavTrap(), FragTrap(), _name("unkown")
{
	std::cout << "<DiamondTrap> default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string Name ) :	
		ClapTrap(Name + "_clap_name"),
		ScavTrap(Name), FragTrap(Name),
		_name(Name)
{
	ScavTrap _holder("holder");

	HP = FragTrap::HP;
	EP = _holder.getEP();
	AD = FragTrap::AD;
	std::cout << "<DiamondTrap> constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& src ) :
		ClapTrap(static_cast<const ClapTrap&>(src)),
		ScavTrap(static_cast<const ScavTrap&>(src)),
		FragTrap(static_cast<const FragTrap&>(src)),
		_name(src._name)
{
	ClapTrap::_name = src._name + "_clap_name";
	std::cout << "<DiamondTrap> copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "<DiamondTrap> destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& src)
{
	if (this != &src)
	{
		_name = src.getName();
		ClapTrap::_name = src.ClapTrap::_name;
		HP = src.HP;
		EP = src.EP;
		AD = src.AD;
	}
	return (*this);
}

std::string	DiamondTrap::getName() const
{
	return (_name);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am ";
	std::cout << _name;
	std::cout << " AKA ";
	std::cout << ClapTrap::getName() << std::endl;
}	