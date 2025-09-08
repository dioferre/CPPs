/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:13:15 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/08 10:13:16 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer( const Serializer& other ) { (void) other; };

Serializer::~Serializer() {};

Serializer&	Serializer::operator=( const Serializer& other )
{
	if (this != &other)
	{
	}
	return (*this);
}

// ==========================================

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (ptr ? reinterpret_cast<uintptr_t>(ptr) : 0);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (raw ? reinterpret_cast<Data *>(raw) : NULL);
}