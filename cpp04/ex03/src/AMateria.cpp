/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:30:32 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/11 16:00:56 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("unknown"), wielder(NULL), is_on_floor(false)
{
}

AMateria::AMateria( const std::string& _type) : type(_type), wielder(NULL), is_on_floor(false)
{	
}

AMateria::AMateria( const AMateria& other )
{
	is_on_floor = other.is_on_floor;
	wielder = other.wielder;
	type = other.type;
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=( const AMateria& other )
{
	if (this != &other)
	{
		is_on_floor = other.is_on_floor;
		wielder = other.wielder;
	}
	return(*this);
}

const std::string&	AMateria::getType() const
{
	return (type);
}

void	AMateria::use( ICharacter& target )
{
	(void) target;
}

void	AMateria::setWielder( ICharacter* target )
{
	wielder = target;
}

ICharacter&	AMateria::getWielder( void )
{
	return (*wielder);
}

void	AMateria::setFloorState( bool state )
{
	is_on_floor = state;
}

bool	AMateria::getFloorState( void )
{
	return (is_on_floor);
}