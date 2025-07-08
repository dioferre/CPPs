/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:40:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 15:44:34 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
}

Cure::Cure( const Cure& other )
{
	*this = other;
}

Cure::~Cure()
{
}

Cure&	Cure::operator=( const Cure& other )
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria*	Cure::clone() const
{
	return ( new Cure );
}

void		Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName()
				<< "'s wounds *" << std::endl;
}