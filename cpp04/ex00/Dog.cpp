/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:47:55 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 13:23:06 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
}

Dog::Dog( const Dog& other ) : Animal(other)
{
}

Dog::~Dog()
{
}

Dog&	Dog::operator=( const Dog& other )
{
	if (this != &other)
	{
		Animal::operator=( other );
	}
	return ( *this );
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}