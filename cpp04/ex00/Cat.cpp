/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:47:53 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 13:31:52 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
}

Cat::Cat( const Cat& other ) : Animal(other)
{
}

Cat::~Cat()
{
}

Cat&	Cat::operator=( const Cat& other )
{
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