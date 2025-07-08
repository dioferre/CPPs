/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:40:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 15:44:41 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
}

Ice::Ice( const Ice& other )
{
	*this = other;
}

Ice::~Ice()
{
}

Ice&	Ice::operator=( const Ice& other )
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria*	Ice::clone() const
{
	return ( new Ice );
}

void		Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName()
				<< " *" << std::endl;
}