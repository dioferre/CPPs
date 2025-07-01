/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:29:42 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 15:31:25 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "<Wrong Cat> default constructor called." << std::endl;
	type = "Wrong Cat";
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other)
{
	std::cout << "<Wrong Cat> copy constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "<Wrong Cat> default destructor called." << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	std::cout << "<Wrong Cat> assignment operator called." << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=( other );
	}
	return ( *this );
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow!" << std::endl;
}