/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:28:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 15:26:20 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "<Animal> default constructor called." << std::endl;
	this->type = "Unknown Animal";
}

Animal::Animal( const Animal& other )
{
	std::cout << "<Animal> copy constructor called." << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "<Animal> default destructor called." << std::endl;
}

Animal& Animal::operator=( const Animal& other )
{
	std::cout << "<Animal> assignment operator called." << std::endl;
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