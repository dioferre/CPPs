/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:47:55 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/21 11:40:38 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "<Dog> default constructor called." << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog( const Dog& other ) : Animal(other)
{
	std::cout << "<Dog> copy constructor called." << std::endl;
	brain = new Brain(*other.brain);
}

Dog::~Dog()
{
	std::cout << "<Dog> default destructor called." << std::endl;
	delete brain;
}

Dog&	Dog::operator=( const Dog& other )
{
	std::cout << "<Dog> assignment operator called." << std::endl;
	if (this != &other)
	{
		Animal::operator=( other );
		brain = other.brain;
	}
	return ( *this );
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}