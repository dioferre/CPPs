/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:30:24 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 13:42:54 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Wrong Animal";
}

WrongAnimal::WrongAnimal( const WrongAnimal& other )
{
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*Wrong Animal Noise*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return ( type );
}