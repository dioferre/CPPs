/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:14:41 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/13 16:11:33 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Utils.hpp"

int MateriaSource::inventory_size = 4;

MateriaSource::MateriaSource()
{
	for (int i = 0; i < inventory_size; i++) {
		known_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	for (int i = 0; i < inventory_size; i++) {
		known_materias[i] = NULL;
	}
	
	copyKnownMaterias(other);
}

MateriaSource::~MateriaSource()
{
	cleanInventory();
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other )
{
	if ( this != &other )
	{
		cleanInventory();
		copyKnownMaterias(other);
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* src)
{
	for (int i = 0; i < inventory_size; i++)
	{
		if ( known_materias[i] == NULL )
		{
			known_materias[i] = src;
			return ;
		}
	}
	
	printError("This Materiasource cannot learn any more materias.");
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0;( i < inventory_size && known_materias[i] != NULL ); i++)
	{
		if ( known_materias[i]->getType() == type )
		{
			return (known_materias[i]->clone());
		}
	}
	
	return (NULL);
	printError("Unknown materia type.");
}

void	MateriaSource::cleanInventory()
{
	for (int i = 0; i < inventory_size; i++)
	{
		if (known_materias[i] != NULL)
		{
			delete known_materias[i];
			known_materias[i] = NULL;
		}
	}
}

void	MateriaSource::copyKnownMaterias( const MateriaSource& other )
{
	for (int i = 0; i < inventory_size; i++)
	{
		if (other.known_materias[i] != NULL)
		{
			known_materias[i] = other.known_materias[i]->clone();
		}
		else
		{
			known_materias[i] = NULL;
		}
	}
}