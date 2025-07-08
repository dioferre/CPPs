/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:30:24 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 15:28:35 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "<Wrong Animal> default constructor called." << std::endl;
	this->type = "Wrong Animal";
}

WrongAnimal::WrongAnimal( const WrongAnimal& other )
{
	std::cout << "<Wrong Animal> copy constructor called." << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "<Wrong Animal> default destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
	std::cout << "<Wrong Animal> assignment operator called." << std::endl;
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