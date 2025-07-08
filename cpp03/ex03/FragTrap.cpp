/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:30:00 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 10:43:47 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	HP = 100;
	EP = 100;
	AD = 30;
	std::cout << "<FragTrap> default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string Name ) : ClapTrap(Name)
{
	HP = 100;
	EP = 100;
	AD = 30;
	std::cout << "<FragTrap> constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& src ) : ClapTrap(src)
{
	std::cout << "<FragTrap> copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "<FragTrap> destructor called" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << BWHITE << "<" << this->_name << "> " << RESET
				<< "gives you a high five!" << std::endl;
}