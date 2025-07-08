/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:47:55 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 15:27:51 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "<Dog> default constructor called." << std::endl;
	type = "Dog";
}

Dog::Dog( const Dog& other ) : Animal(other)
{
	std::cout << "<Dog> copy constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "<Dog> default destructor called." << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	std::cout << "<Dog> assignment operator called." << std::endl;
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