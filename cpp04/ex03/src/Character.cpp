/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:06:30 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/12 18:17:57 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int Character::max_floor_items = 50;
int Character::inventory_size = 4;
AMateria *Character::floor[50] = {NULL};

Character::Character() : ICharacter()
{
	for (int i = 0; i < inventory_size; ++i) {
		inventory[i] = NULL;
	}
}

Character::Character( std::string _name) : ICharacter(), name(_name)
{
	for (int i = 0; i < inventory_size; ++i) {
		inventory[i] = NULL;
	}
}

Character::Character( const Character& other)
{
	for (int i = 0; i < inventory_size; ++i) {
		inventory[i] = NULL;
	}
	*this = other;
}

Character::~Character()
{
	for (int i = 0; i < inventory_size; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}

	for (int i = 0; i < max_floor_items && floor[i] != NULL; i++)
	{
		delete floor[i];
		floor[i] = NULL;
	}
}

// Need to test this better
Character&	Character::operator=( const Character& other )
{
	if (this != &other)
	{
		for (int i = 0; i < inventory_size; i++)
		{
			if (inventory[i] != NULL)
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		
		name = other.name;

		for (int i = 0; i < inventory_size; i++) {
			inventory[i] = other.inventory[i];
		}
	}
	return (*this);
}

const std::string& Character::getName() const
{
	return (name);
}

void	Character::equip( AMateria* m )
{
	if (!isMateriaEquippable(m))
		return ;

	for (int i = 0; i < inventory_size; i++)
	{
		if (inventory[i] == NULL)	// Empty slot found, materia not yet equipped.
		{
			if (m->getFloorState() == true)
			{
				pickItem(*m);
			}
			else
			{
				m->setWielder(this);
			}
			inventory[i] = m;
			return ;
		}
	}
}
 
void	Character::unequip( int idx )
{
	if (!isValidIndex( idx )) {
		return ;
	}

	for (int i = 0; i <= idx; i++)
	{
		if (i == idx && inventory[i] != NULL)
		{
			dropItem( *inventory[i] );
			inventory[i] = NULL;
			return ;
		}
	}

	std::cout << RED << "[ERROR]: " << RESET
			<< "Cannot unequip item, no item in slot " << idx << "."
			<< std::endl;
}

void	Character::use( int idx, ICharacter& target )
{
	if (!isValidIndex( idx )) {
		return ;
	}

	for (int i = 0; i <= idx; i++)
	{
		if (i == idx && inventory[i] != NULL)
		{
			inventory[i]->use(target);
			return ;
		}
	}

	std::cout << RED << "[ERROR]: " << RESET
			<< "Cannot use item, no item in slot " << idx << "."
			<< std::endl;
}

void	Character::dropItem( AMateria& item )
{
	for (int i = 0; i < max_floor_items; i++)
	{
		if (floor[i] == NULL)
		{
			floor[i] = &item;
			item.setWielder(NULL);
			item.setFloorState(true);
			return ;
		}
	}
	printError("Cannot drop item, the floor is full. This item won't be equipped.");
}

void	Character::pickItem( AMateria& item )
{
	int	pop_index;
	
	for (int i = 0; (i < max_floor_items && floor[i] != NULL); i++)
	{
		if (floor[i] == &item)
			pop_index = i;
	}
	
	rebuildFLoorArray( pop_index );

	item.setFloorState(false);
	item.setWielder(this);
}

void	Character::rebuildFLoorArray( int pop_index )
{
	AMateria* tmp[50];
	
	for (int i = 0; i < max_floor_items; i++)
	{
		tmp[i] = floor[i];
	}
	
	for (int i = 0; i < max_floor_items - 1; i++)
	{
		if ( i >= pop_index )
			floor[i] = tmp[i + 1];
	}
	floor[max_floor_items - 1] = NULL;
}

bool	Character::isValidIndex( int idx )
{
	if (0 > idx || idx > inventory_size - 1)
	{
		printError("Invalid inventory index");
		return (false);
	}
	return (true);
}

bool	Character::isMateriaEquippable( AMateria* m )
{
	if (m == NULL)
	{
		printError("Cannot equip a NULL materia, nothing will be done.");
		return ( false );
	}
	else if ( m->getWielder() == this )
	{
		printError("This materia is already equipped, nothing will be done.");
		return ( false );
	}
	else if ( m->getWielder() != NULL )
	{
		printError("This materia is already in another character's inventory, nothing will be done.");
		return ( false );
	}
	for (int i = 0; i < inventory_size; i++)
	{
		if ( inventory[i] == NULL )
			break;
		else if ( i == inventory_size - 1 )
		{
			printError("Inventory is full, please unequip an item before equipping a new one.");
			return ( false );
		}
	}
	return (true);
}