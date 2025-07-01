/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:29:42 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 13:42:58 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "Wrong Cat";
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other)
{
}

WrongCat::~WrongCat()
{
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
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