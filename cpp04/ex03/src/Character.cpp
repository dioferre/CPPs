/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:06:30 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/11 18:36:24 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int Character::max_floor_items = 50;
AMateria *Character::floor[50] = {NULL};

Character::Character() : ICharacter()
{
	for (int i = 0; i < 4; ++i) {
		inventory[i] = NULL;
	}
}

Character::Character( std::string _name) : ICharacter(), name(_name)
{
	for (int i = 0; i < 4; ++i) {
		inventory[i] = NULL;
	}
}

Character::Character( const Character& other)
{
	for (int i = 0; i < 4; ++i) {
		inventory[i] = NULL;
	}
	*this = other;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

Character&	Character::operator=( const Character& other )
{
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (inventory[i] != NULL)
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		
		name = other.name;

		for (size_t i = 0; i < 4; i++) {
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
	if (m == NULL)
	{
		printError("Cannot equip a NULL materia, nothing will be done.");
		return ;
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] == m)
		{
			printError("Materia already equipped, nothing will be done.");
			return ;
		}
		else if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return;
		}
	}

	printError("Inventory full.");
}
 
void	Character::unequip( int idx )
{
	if (idx < 0 || idx > 3)
	{
		printError("Invalid inventory index");
		return;
	}

	for (int i = 0; i <= idx; i++)
	{
		if (i == idx && inventory[i] != NULL)
		{
			inventory[i] = NULL;
		}
	}
	
}

void	Character::use( int idx, ICharacter& target )
{
	if (0 > idx || idx > 3)
	{
		printError("Invalid inventory index");
		return;
	}

	for (int i = 0; i <= idx; i++)
	{
		if (i == idx && inventory[i] != NULL)
		{
			inventory[i]->use(target);
		}
	}
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

// Need to check these two following functions better and improve on them
void	Character::pickItem( AMateria& item )
{
	int	pop_item_idx;
	
	// Find Item
	for (int i = 0; (i < max_floor_items && floor[i] != NULL); i++)
	{
		if (floor[i] == &item)
			pop_item_idx = i;
	}
	

	rebuild_floor_array( pop_item_idx );
}

void	Character::rebuild_floor_array( int pop_item_idx )
{
	AMateria* tmp[50];
	
	for (int i = 0; i < max_floor_items; i++)
	{
		tmp[i] = floor[i];
	}
	
	for (int i = 0; i < max_floor_items - 1; i++)
	{
		if ( i >= pop_item_idx )
			floor[i] = tmp[i + 1];
	}
	floor[50] = NULL;
	
	delete[] tmp;
}