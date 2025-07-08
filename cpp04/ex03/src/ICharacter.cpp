/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:03:53 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 15:06:27 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
}

ICharacter::ICharacter( const ICharacter& other)
{
	(void) other;
}

ICharacter::~ICharacter()
{
}

ICharacter&	ICharacter::operator=( const ICharacter& other )
{
	(void) other;

	return (*this);
}