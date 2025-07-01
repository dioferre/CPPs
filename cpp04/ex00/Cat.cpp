/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:47:53 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 15:27:02 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "<Cat> default constructor called." << std::endl;
	type = "Cat";
}

Cat::Cat( const Cat& other ) : Animal(other)
{
	std::cout << "<Cat> copy constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "<Cat> default destructor called." << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	std::cout << "<Cat> assignment operator called." << std::endl;
	if (this != &other)
	{
		Animal::operator=( other );
	}
	return ( *this );
}

void	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}