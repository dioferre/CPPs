/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:33:24 by dioferre          #+#    #+#             */
/*   Updated: 2025/05/18 15:51:19 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon( std::string type )
{
	this->type = type;
}

Weapon::~Weapon()
{
}

void	Weapon::setType( std::string type )
{
	this->type = type;
}

std::string	Weapon::getType( void )
{
	return (this->type);
}
