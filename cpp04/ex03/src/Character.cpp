/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:06:30 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 16:11:23 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter()
{
	for (int i = 0; i < 4; ++i) {
		inventory[i] = nullptr;
	}
}

Character::Character( std::string _name) : ICharacter(), name(_name)
{
	for (int i = 0; i < 4; ++i) {
		inventory[i] = nullptr;
	}
}

Character::Character( const Character& other)
{
	for (int i = 0; i < 4; ++i) {
		inventory[i] = nullptr;
	}
	*this = name;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] != nullptr)
			delete inventory[i];
	}
}

Character&	Character::operator=( const Character& other )
{
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (inventory[i] != nullptr)
			{
				delete inventory[i];
				inventory[i] = nullptr;
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
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] == nullptr)
		{
			inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip( int idx )
{
	if (idx < 0 && idx > 3)
	{
		return;
	}

	for (size_t i = 0; i <= idx; i++)
	{
		if (i == idx && inventory[i] != nullptr)
		{
			inventory[i] = nullptr;
		}
	}
	
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx < 0 && idx > 3)
	{
		return;
	}

	for (size_t i = 0; i <= idx; i++)
	{
		if (i == idx && inventory[i] != nullptr)
		{
			inventory[i]->use(target);
		}
	}
}