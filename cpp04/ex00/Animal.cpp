/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:28:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 13:42:48 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Unknown Animal";
}

Animal::Animal( const Animal& other )
{
	*this = other;
}

Animal::~Animal()
{
}

Animal& Animal::operator=( const Animal& other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << std::endl;
}

std::string Animal::getType() const
{
	return ( type );
}