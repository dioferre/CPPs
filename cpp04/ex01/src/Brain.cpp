/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:41:46 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/04 10:37:40 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "<Brain> default constructor called." << std::endl;
}

Brain::Brain( const Brain& other )
{
	std::cout << "<Brain> copy constructor called." << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "<Brain> default destructor called." << std::endl;
}

Brain&	Brain::operator=( const Brain& other )
{
	std::cout << "<Brain> assignment operator called." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return ( *this );
}