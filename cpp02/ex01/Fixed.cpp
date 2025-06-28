/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:41:06 by dioferre          #+#    #+#             */
/*   Updated: 2025/05/27 17:09:53 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

const int	Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed( const Fixed& toCopy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

Fixed::Fixed( const int nr )
{
	std::cout << "Int constructor called" << std::endl;

	value = nr << fractionalBits;
}

Fixed::Fixed( const float nr )
{
	std::cout << "Float constructor called" << std::endl;

	value = roundf(nr * (1 << fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed	&Fixed::operator=( const Fixed& src )
{
	std::cout << "Copy assignment operator called" << std::endl;

	if ( this != &src )
		this->value = src.getRawBits();
	return ( *this );
}

int		Fixed::getRawBits( void ) const
{
	return ( this->value );
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}


std::ostream	&operator<<( std::ostream &os, Fixed const &fixed )
{
	os << fixed.toFloat();
	return ( os );
}


float	Fixed::toFloat( void ) const
{
	return ((float)value / (float)(1 << fractionalBits));
}


int		Fixed::toInt( void ) const
{
	return (value >> fractionalBits);
}