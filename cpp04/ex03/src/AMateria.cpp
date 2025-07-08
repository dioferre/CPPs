/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:30:32 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 14:50:57 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("unknown")
{
}

AMateria::AMateria( const std::string& _type) : type(_type)
{	
}

AMateria::AMateria( const AMateria& other )
{
	*this = other;
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=( const AMateria& other )
{
	if (this != &other)
	{
		
	}
	return(*this);
}

const std::string&	AMateria::getType() const
{
	return (type);
}
