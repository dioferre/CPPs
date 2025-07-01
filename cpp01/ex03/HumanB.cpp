/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:47:28 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 11:28:47 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon( Weapon &weapon )
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout <<_name << " cannot attack because they don't have a weapon." << std::endl;
}

