/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:30:00 by dioferre          #+#    #+#             */
/*   Updated: 2025/06/28 15:15:35 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	HP = 100;
	EP = 100;
	AD = 30;
}

FragTrap::FragTrap( std::string Name ) : ClapTrap(Name)
{
	std::cout << BWHITE << "<FragTrap>"
				<< GREEN " Constructor" << RESET
				<< " called." << std::endl;
	HP = 100;
	EP = 100;
	AD = 30;
}

FragTrap::FragTrap( const FragTrap& src ) : ClapTrap(src.getName())
{
}

FragTrap::~FragTrap()
{
	std::cout << BWHITE << "<FragTrap>"
				<< RED " Destructor" << RESET
				<< " called." << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& src)
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

void	FragTrap::highFivesGuys( void )
{
	std::cout << BWHITE << "<" << this->_name << "> " << RESET
				<< "gives you a high five!" << std::endl;
}