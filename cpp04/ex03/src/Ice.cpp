/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:40:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/21 14:52:20 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice( const Ice& other )
{
	*this = other;
	type = other.type;
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
	return ( new Ice(*this) );
}

void		Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName()
				<< " *" << std::endl;
}
